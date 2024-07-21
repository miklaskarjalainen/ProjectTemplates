cmake_minimum_required(VERSION 3.28)
include(FetchContent)
project(SDL3_Template)

# Build SDL3 as static library
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Fetch Libraries
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL/
  GIT_TAG f244f08165d08bc9cbef460aaec11e70ba43d8b6
)
FetchContent_MakeAvailable(SDL3)

set(CXX_STANDARD 17)
set(SOURCE_FILES
  src/main.cpp
)

set(INCLUDE_DIRS
  src
  SDL3::SDL3
)

set(LIBS
  SDL3::SDL3
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
