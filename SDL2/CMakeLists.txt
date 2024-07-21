cmake_minimum_required(VERSION 3.28)
include(FetchContent)
project(SDL2_Template)

# Build SDL2 as a static library 
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Fetch Libraries
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL/
  GIT_TAG 2eef7ca475decd2b864214cdbfe72b143b16d459 # 2.30.5
)
FetchContent_MakeAvailable(SDL2)

set(CXX_STANDARD 17)
set(SOURCE_FILES
  src/main.cpp
)

set(INCLUDE_DIRS
  src
  SDL2::SDL2
)

set(LIBS
  SDL2::SDL2
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})

