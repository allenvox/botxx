#include <tgbot/tgbot.h>

#include <iostream>

const std::string prefix = "[botxx] ";

int main() {
  // getting token
  std::cout << prefix << "enter Telegram API token file path > ";
  std::string path;
  std::getline(std::cin, path);
  std::ifstream tokenFile(path);
  if (!tokenFile.is_open()) {
    throw std::runtime_error("Can't open token file " + path);
  }
  std::string token;
  std::getline(tokenFile, token);

  TgBot::Bot bot(token); // bot initialisation

  // "/start" command respond
  bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, "Hi!");
  });

  // any message respond
  bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    std::cout << prefix << message->from->username << ": \""
              << message->text.c_str() << "\"\n";
    // except "/start" command
    if (StringTools::startsWith(message->text, "/start")) {
      return;
    }
    bot.getApi().sendMessage(message->chat->id,
                             "You said \"" + message->text + "\"");
  });

  try {
    std::cout << prefix << '@' << bot.getApi().getMe()->username.c_str()
              << " started\n";
    TgBot::TgLongPoll longPoll(bot);
    while (true) {
      longPoll.start();
      // std::cout << prefix << "long poll started\n";
    }
  } catch (TgBot::TgException &e) {
    std::cerr << prefix << "ERROR: " << e.what() << '\n';
  }
  return 0;
}