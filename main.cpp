#include "lib.hpp"
#include <spdlog/spdlog.h>

int main ()
{   
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("версия {} запущена успешно!", version());

    return 0;
}
