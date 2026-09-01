# Minimun required CMake version for the upgraded baseline
cmake_minimum_required(VERSION 4.3.1)

# Project name and language
project(cpp-oop-review LANGUAGES CXX)

# Cmake version check
if (CMAKE_VERSION VERSION_LESS "4.3.1")
    message(FATAL_ERROR "CMake version 4.3.1 or higher required")
endif ()

# Compiler version check and C++26 support check
include(CheckCXXSourceCompiles)
set(CMAKE_REQUIRED_FLAGS "{CMAKE_REQUIRED_FLAGS} -std=c++26")
check_cxx_source_compiles("int main() { return 0;}" CXX26_SUPPORTED)
if (NOT CXX26_SUPPORTED)
    message(FATAL_ERROR "C++26 is not supported compiler.")
endif ()

# Add a custom target to validate the upgrade

#Source files
set(SOURCES
    main.cpp
)

#Define the executable target
add_executable(cpp-oop-review ${SOURCES})

# Keep language settings and include paths target-coped
set_target_properties(cpp-oop-review PROPERTIES
    CXX_STANDARD 26
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)


target_include_directories(cpp-opp-review PRIVATE ${PROJECT_SOURCES_DIR}/include)
add_custom_target(validate-upgrate
COMMAND ${MAKE_COMMAND} -E echo "validated toolchain: CMake ${CMAKE_VERSION}/ ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}/ c++26"
VERBATIM)
