# Copyright (c) Microsoft Corporation. All rights reserved.
# SPDX-License-Identifier: MIT

cmake_minimum_required (VERSION 3.12)

project (azure-core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

#add_library (
#  azure-core
#  )

#target_include_directories (azure-core PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc> $<INSTALL_INTERFACE:include/az>)

#add_library (azure::core ALIAS azure-core)

add_executable (
  azure-core_test
  test/main.cpp 
   "inc/_internal/cfg.hpp" "inc/_internal/prefix.hpp" "inc/_internal/suffix.hpp")

#target_link_libraries(azure-core-test PRIVATE azure-core)
#target_include_directories (azure-core-test PRIVATE inc)

if (UNIX)
  target_link_libraries(azure-core-test PRIVATE m)
endif()

#target_include_directories (azure-core-test PRIVATE test)

add_test(NAME azure-core-test COMMAND azure-core-test)
