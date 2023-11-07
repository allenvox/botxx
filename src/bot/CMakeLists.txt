set(target_name bot)
add_executable(${target_name})
set_compile_options(${target_name})
target_sources(
        ${target_name}
        PRIVATE
        main.cpp
)
target_link_libraries(
        ${target_name}
        PRIVATE
        TgBot
        ${CMAKE_THREAD_LIBS_INIT}
        ${OPENSSL_LIBRARIES}
        ${Boost_LIBRARIES}
        ${CURL_LIBRARIES}
)