cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CitiBike)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# Add all source files in the "src" directory
file(GLOB SOURCES "src/*.cpp")

# Add all header files in the "include" directory
file(GLOB HEADERS "include/*.h")

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Create the executable
add_executable(CitiBike ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(CitiBike PRIVATE include)

