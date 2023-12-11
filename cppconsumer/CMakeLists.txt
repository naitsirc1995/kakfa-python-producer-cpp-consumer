cmake_minimum_required(VERSION 3.12)
project(learning-cmake)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC rdkafka rdkafka++)