#include "sylar/log.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(int argc, char** argv) {
    sylar::LogLevel log;
    std::cout << log.DEBUG << std::endl;
    return 0;
}