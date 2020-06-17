#include "version.h"    // этот файл мы сгенерируем cmake
#include <iostream>     // 
#include "lib.hpp"      // объявление version ()

int version()
{
    std::cout<<"запуск функции version() ";
    return PROJECT_VERSION_PATCH;
}
