idf_component_register(SRCS "app_main.cpp" "camera_server.cpp"
                    INCLUDE_DIRS "." "include")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
