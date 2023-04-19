cmake_minimum_required(VERSION 3.25)
project(dclist C)

set(CMAKE_C_STANDARD 11)

add_executable(dclist main.c dclist.h common.h)
