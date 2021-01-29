# cmake_minimum_required(VERSION <specify CMake version here>)
project(YUVImageTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(YUVImageTest main.cpp YUVImage.cpp include/YUVImage.h)