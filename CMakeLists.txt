
cmake_minimum_required (VERSION 3.2)                                            # минимальаня версия CMake 

               project (my_tutor_first VERSION 0.0.1$ENV{TRAVIS_BULD_NUMBER})   # создание виртуального проекта my_tutor_first а так же номера версии

          find_package (Threads REQUIRED)                                       # искать потоки
          find_package (Boost   COMPONENTS unit_test_framework REQUIRED)        # искать boost

        configure_file (version.h.in ${PROJECT_SOURCE_DIR}/version.h)           # создать version.h на основании version.h.in
        
        add_executable (helloworld_for_client    main.cpp)                        # создать бинарник
           add_library (helloworld_lib            lib.cpp)                        # создать библиотеку k
        add_executable (helloworld_test  test_version.cpp)   
    
 set_target_properties (helloworld_for_client helloworld_lib                    # 
                       PROPERTIES                                               # 
                       CXX_STANDARD 17                                          # 
                       CXX_STANDARD_REQUIRED ON                                 # 
                       COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"               # 
                       )

target_link_libraries (helloworld_for_client                                    # 
                       helloworld_lib                                           # 
                       Threads::Threads                                         # 
                       )    
 target_link_libraries (helloworld_test
                       ${Boost_LIBRARIES}
                       helloworld_lib
                       )
              install (TARGETS  helloworld_for_client                           # 
                       RUNTIME DESTINATION  bin                                 # 
                       )

 set_target_properties (helloworld_test PROPERTIES
                       COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
                       INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
                       )

    set(CPACK_GENERATOR  DEB)                                                   # 

    set(CPACK_PACKAGE_VERSION_MAJOR     "${PROJECT_VERSION_MAJOR}")             # 
    set(CPACK_PACKAGE_VERSION_MINOR     "${PROJECT_VERSION_MINOR}")             # 
    set(CPACK_PACKAGE_VERSION_PATCH     "${PROJECT_VERSION_PATCH}")             # 

    set(CPACK_PACKAGE_CONTACT           rassant@mail.ru)                        # 
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS  ON)                                     # 

    include (CPack)                                                             # 

    enable_testing()
    add_test (tests_from_my_CMake helloworld_test)

