cmake_minimum_required(VERSION 3.0)

project(bleak)

set (BLEAK_VERSION_MAJOR 0)
set (BLEAK_VERSION_MINOR 1)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(REQUIRED_PYTHON_VERSION 3.5)

  message(STATUS "======== LOOKING FOR Python ${REQUIRED_PYTHON_VERSION} ========================")
  find_package ( PythonInterp ${REQUIRED_PYTHON_VERSION} REQUIRED)
  find_package ( PythonLibs ${PYTHON_VERSION_STRING} EXACT)
  # find_package ( PythonLibs ${PYTHON_VERSION_STRING} EXACT REQUIRED )

  message(STATUS "PYTHON_EXECUTABLE:FILEPATH=${PYTHON_EXECUTABLE}")
  message(STATUS "PYTHON_LIBRARY:FILEPATH=${PYTHON_LIBRARY}")
  message(STATUS "PYTHON_INCLUDE_DIR:FILEPATH=${PYTHON_INCLUDE_DIR}")
  message(STATUS "PYTHON_FRAMEWORK_INCLUDES=${PYTHON_FRAMEWORK_INCLUDES}")
  message(STATUS "PYTHONLIBS_VERSION_STRING=${PYTHONLIBS_VERSION_STRING}")
  message(STATUS "Python_FRAMEWORKS=${Python_FRAMEWORKS}")

############################# Find Python Done ####################################

include_directories(${PYTHON_INCLUDE_DIR})
add_subdirectory(server)
add_subdirectory(client)

add_executable(bleak_server
               ${BLEAK_SERVER_SRCS})

add_executable(bleak_client
               ${BLEAK_CLIENT_SRCS})

link_directories(bleak_server ${PYTHON_LIBRARY})
link_directories(bleak_client ${PYTHON_LIBRARY})

target_link_libraries(bleak_server ${PYTHON_LIBRARY})
target_link_libraries(bleak_client ${PYTHON_LIBRARY})

install (TARGETS bleak_client DESTINATION bin)
install (TARGETS bleak_server DESTINATION bin)