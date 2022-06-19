cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME enum_devices)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.c)

### https://stackoverflow.com/questions/71531333/how-set-cmake-to-find-a-local-package-ffmpeg
### https://cmake.org/cmake/help/latest/module/FindPkgConfig.html#command:pkg_check_modules
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

target_link_libraries(${PROJECT_NAME} PUBLIC PkgConfig::LIBAV)
