#include "sylar/log.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(int argc, char** argv) {
    sylar::LogLevel log;
    std::cout << log.ToString(sylar::LogLevel::DEBUG) << std::endl;
    std::cout << log.FromString("error") << std::endl;
    return 0;
}