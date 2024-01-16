cmake_minimum_required(VERSION 3.8)
project(my_cpp_library)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

### include(/opt/my/parasoft/cpptest/integration/cmake/cpptest-project.cmake)

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# tell CMake to add this directory to the target including path
include_directories(include/my_cpp_library)
# you can use the file you are using but this is mostly for multiple head
set(HEADER_FILES include/my_cpp_library/library_header.h)
add_library(my_lib src/my_cpp_library.cpp ${HEADER_FILES})

add_executable(main src/main.cpp)
# this is important to tell CMake that the executable "main" depends on the
target_link_libraries(main PUBLIC my_lib)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

 find_package(ament_cmake_gtest REQUIRED)
 set(TESTFILES
     test/testmain.cpp
     test/savings_account_test.cpp
 )
 # Add gtest executables
 ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
 target_link_libraries(${PROJECT_NAME}_test my_lib)

 install(TARGETS
     ${PROJECT_NAME}_test
     # install the generated test executable file to the path after DESTINATION
     DESTINATION lib/${PROJECT_NAME})

endif()

ament_package()
