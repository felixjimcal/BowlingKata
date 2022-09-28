cmake_minimum_required(VERSION 3.5)

project(cpp_BowlingKata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cpp_BowlingKata main.cpp)
add_executable(Tests bowling_tests.cpp)

enable_testing()

target_link_libraries(
  Tests
  gtest_main
)

install(TARGETS cpp_BowlingKata
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

include(GoogleTest)
gtest_discover_tests(Tests)
