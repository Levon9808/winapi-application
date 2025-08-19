cmake_minimum_required(VERSION 3.16)

project(Stroyka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Stroyka WIN32
    main.cpp
    basewindow.cpp
    basewindow.h
)

if (MINGW)
    target_link_options(Stroyka PRIVATE -municode)
endif()

target_compile_definitions(Stroyka PRIVATE UNICODE _UNICODE)

