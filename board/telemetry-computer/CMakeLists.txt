 add_library(target_platform OBJECT)
 add_subdirectory(cmake/stm32cubemx EXCLUDE_FROM_ALL)

 get_target_property(CUBEMX_SOURCES stm32cubemx INTERFACE_SOURCES)
 target_sources(target_platform PRIVATE ${CUBEMX_SOURCES})

 get_target_property(CUBEMX_INCLUDES stm32cubemx INTERFACE_INCLUDE_DIRECTORIES)
 get_target_property(CUBEMX_COMPILE_DEFS stm32cubemx INTERFACE_COMPILE_DEFINITIONS)
 get_target_property(CUBEMX_LINK_DIRS stm32cubemx INTERFACE_LINK_DIRECTORIES)
 get_target_property(CUBEMX_LINK_LIBS stm32cubemx INTERFACE_LINK_LIBRARIES)

 target_include_directories(target_platform PUBLIC ${CUBEMX_INCLUDES})
 target_compile_definitions(target_platform PUBLIC ${CUBEMX_COMPILE_DEFS})
 if(CUBEMX_LINK_DIRS)
 	target_link_directories(target_platform PUBLIC ${CUBEMX_LINK_DIRS})
 endif()
 if(CUBEMX_LINK_LIBS)
 	target_link_libraries(target_platform PUBLIC ${CUBEMX_LINK_LIBS})
 endif()
 target_compile_options(target_platform INTERFACE
 	-include stm32f4xx.h 
 )
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/drivers ${CMAKE_BINARY_DIR}/lib/drivers)

 add_library(board_config STATIC)

 target_sources(board_config PRIVATE 
 	${CMAKE_CURRENT_LIST_DIR}/bsp/bsp.cpp
 )

 target_include_directories(board_config PRIVATE
 	${CMAKE_SOURCE_DIR}/src/bsp
 )

target_link_libraries(board_config PRIVATE 
    target_platform
PUBLIC
    drivers
)