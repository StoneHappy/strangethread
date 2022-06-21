#include "sqlPool.h"
#include <fstream>
#include <iostream>

bool sqlPool::ParseJson()
{
    return true;

}

void sqlPool::produce()
{
    std::cout << "produce begin" << std::endl;
    while(true)
    {
        
    }
    std::cout << "produce end" << std::endl;
}


void sqlPool::recycle()
{
    std::cout << "recycle begin" << std::endl;
    while(true)
    {
        
    }
    std::cout << "recycle end" << std::endl;
}

sqlPool::sqlPool()
{
    std::cout << "sql Pool construct" << std::endl;
    thread producer(&sqlPool::produce,this);
    thread recycler(&sqlPool::recycle,this);
    producer.detach();
    recycler.detach();
}

sqlPool::~sqlPool()
{
    std::cout << "sql Pool destroy" << std::endl;
}