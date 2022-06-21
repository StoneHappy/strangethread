#pragma once
#include <string>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;
//使用单例设计模式
class sqlPool{
public:
    static sqlPool* GetInstance(){
        static sqlPool pool;
        return &pool;
    }
    sqlPool(sqlPool& pool) = delete;
    void operator=(sqlPool& pool) = delete;
    void produce();
    void recycle();
private:
    string m_user;
    string m_passwd;
    string m_database;
    string m_ip;
    unsigned short m_port;
    int m_minSize;
    int m_maxSize;
    int m_timeout;
    int m_maxIdelTime;
    mutex m_mutex;
    condition_variable m_cond;

private:
    bool ParseJson();
    sqlPool();
    ~sqlPool();
};