cmake_minimum_required(VERSION 3.0.0)
project(DelayDel VERSION 0.1.0)
message(${CMAKE_SOURCE_DIR})
set(ROOT_DIR ${CMAKE_SOURCE_DIR})

include_directories(Lib)
include_directories(Src)

file (GLOB LIB_FILES "Lib/*.c")
file (GLOB SRC_FILES "Src/*.c")
add_executable(${PROJECT_NAME} ${SRC_FILES} ${LIB_FILES})
