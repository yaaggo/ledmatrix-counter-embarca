cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)
project(ledmatrix-counter C CXX ASM)
pico_sdk_init()

file(GLOB LIBSOURCES "include/*.c")
file(GLOB SRCSOURCES "src/*.c")

add_executable(ledmatrix-counter ${SRCSOURCES} ${LIBSOURCES} )

pico_set_program_name(ledmatrix-counter "ledmatrix-counter")
pico_set_program_version(ledmatrix-counter "0.1")

# Generate PIO header
pico_generate_pio_header(ledmatrix-counter ${CMAKE_CURRENT_LIST_DIR}/include/ws2818b.pio)

pico_enable_stdio_uart(ledmatrix-counter 1)
pico_enable_stdio_usb(ledmatrix-counter 1)

target_link_libraries(ledmatrix-counter
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(ledmatrix-counter PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(ledmatrix-counter 
        hardware_pio
        hardware_clocks
        hardware_pwm
        )

pico_add_extra_outputs(ledmatrix-counter)

