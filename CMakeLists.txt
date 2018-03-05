# 声明要求的cmake最低版本
cmake_minimum_required( VERSION 2.8 )

project(useEigen)

set( CMAKE_BUILD_TYPE "Debug" )

include_directories( "/usr/include/eigen3")

add_executable( useMatrix useMatrix.cpp)
