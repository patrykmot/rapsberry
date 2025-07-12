cmake_minimum_required(VERSION 3.10)

project(rpi_hello_world LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/lib/sht35)

add_executable(rpi_hello_world src/main.cpp)

target_link_libraries(rpi_hello_world sht35)