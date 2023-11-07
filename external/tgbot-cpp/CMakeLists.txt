include(FetchContent)

FetchContent_Declare(
        TgBot
        GIT_REPOSITORY https://github.com/reo7sp/tgbot-cpp
        GIT_TAG v1.7.2
        GIT_SHALLOW TRUE
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}
)

FetchContent_MakeAvailable(TgBot)