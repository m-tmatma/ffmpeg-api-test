cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME ffmpeg-api-test)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(enum_devices)
