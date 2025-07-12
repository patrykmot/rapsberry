add_library(sht35 STATIC driver_sht35_basic.c driver_sht35.c iic.c raspberrypi4b_driver_sht35_interface.c)

target_include_directories(sht35 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})