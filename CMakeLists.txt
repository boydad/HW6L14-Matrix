cmake_minimum_required(VERSION 3.5)

project(HW6L14-Matrix)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GetGitRevisionDescription)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(matrix ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${version_file})

set_target_properties(matrix PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_FLAGS "-Wpedantic -Wall -Wextra"
)

install(TARGETS matrix DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${VERSION_SHORT})
set(CPACK_PACKAGE_CONTACT xxx@xxx.xx)

include(CPack)
