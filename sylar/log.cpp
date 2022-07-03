#include "log.h"
#include <map>
#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>

namespace sylar {
    const char* LogLevel::ToString(LogLevel::Level level) {
        switch (level) {
    #define XX(name) \
        case LogLevel::name: \
            return #name; \
            break;

        XX(DEBUG);
        XX(INFO);
        XX(WARN);
        XX(ERROR);
        XX(FATAL);
    #undef XX
        default:
            return "UNKNOW";
        }
        return "UNKNOW";
    }

    LogLevel::Level LogLevel::FromString(const std::string& str) {
        #define XX(level, v) \
            if(str == #v) { \
                return LogLevel::level; \
            }
            XX(DEBUG, debug);
            XX(INFO, info);
            XX(WARN, warn);
            XX(ERROR, error);
            XX(FATAL, fatal);

            XX(DEBUG, DEBUG);
            XX(INFO, INFO);
            XX(WARN, WARN);
            XX(ERROR, ERROR);
            XX(FATAL, FATAL);
            return LogLevel::UNKNOW;
        #undef XX
    }

    LogEvent::LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level
            ,const char* file, int32_t line, uint32_t elapse
            ,uint32_t thread_id, uint32_t fiber_id, uint64_t time
            ,const std::string& thread_name)
        :m_file(file)
        ,m_line(line)
        ,m_elapse(elapse)
        ,m_threadId(thread_id)
        ,m_fiberId(fiber_id)
        ,m_time(time)
        ,m_threadName(thread_name)
        ,m_logger(logger)
        ,m_level(level) {
    }

    // 可变参数列表，先初始化一个 va_list，而后将至臻zhi向 fmt，format 中获取内容，最终 va_end 释放指针
    void LogEvent::format(const char* fmt, ...) {
        va_list al;
        va_start(al, fmt);
        format(fmt, al);
        va_end(al);
    }

    void LogEvent::format(const char* fmt, va_list al) {
        char* buf = nullptr;
        //vasprintf()函数 :int vasprintf (char **buf, const char *format, va_list ap)
        // 将格式化数据从可变参数列表写入缓冲区
        int len = vasprintf(&buf, fmt, al);
        if(len != -1) {
            m_ss << std::string(buf, len);
            free(buf);
        }
    }

}