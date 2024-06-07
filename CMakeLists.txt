cmake_minimum_required(VERSION 3.5)

project(06_homework)

add_executable(application application.cpp)
set_target_properties(application PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)