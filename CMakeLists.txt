cmake_minimum_required(VERSION 3.8)
project(amigasprite)

set(SRC ${CMAKE_SOURCE_DIR}/src)

add_executable(amigasprite
	${SRC}/main.c
)

install(TARGETS amigasprite
    COMPONENT linapp
    RUNTIME DESTINATION "/bin/"
    LIBRARY DESTINATION "/lib/"
    DESTINATION "/bin/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)
