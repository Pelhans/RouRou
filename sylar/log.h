#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdarg.h>
#include <map>

namespace sylar {

class Logger;
class LoggerManager;

/**
 * @brief 日志级别
 */
class LogLevel {
public:
    /**
     * @brief 日志级别枚举
     */
    enum Level {
        // 未知级别
        UNKNOW = 0,
        DEBUG  = 1,
        INFO   = 2,
        WARN   = 3,
        ERROR  = 4,
        FATAL  = 5
    };
};


}

#endif