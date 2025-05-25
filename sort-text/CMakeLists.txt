cmake_minimum_required(VERSION 3.29)
project(sort_text C)

set(CMAKE_C_STANDARD 11)

add_executable(sort_text main.c)

# === Test executable ===
# Add test files + the code you're testing (if it's in main.c or split out)
add_executable(sort_text_tests tests/tests_sort.c main.c)

# Include CUnit headers
include_directories(/opt/homebrew/include)

# Link against the CUnit library
link_directories(/opt/homebrew/lib)
target_link_libraries(sort_text_tests cunit)

# Enable CTest integration
enable_testing()
add_test(NAME run_sort_tests COMMAND sort_text_tests)