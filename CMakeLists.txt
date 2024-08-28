cmake_minimum_required(VERSION 3.29)
project(Bits C)
enable_language(C ASM)

set(CMAKE_C_STANDARD 11)

set ( SOURCES
        main.c
        )

add_executable(program  ${SOURCES} )

