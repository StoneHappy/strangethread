#include "sqlPool.h"
#include <iostream>

namespace testStrangeThread {

//不用数据库连接池
int op1(int num) {
  for (int i = 0; i < num; ++i) {
  }
  return 0;
}

void op2(int num, sqlPool *pool) {
  for (int i = 0; i < num; ++i) {
  }
}

void test2() {
  chrono::steady_clock::time_point begin = chrono::steady_clock::now();
  sqlPool *pool = sqlPool::GetInstance();
  thread t1(op2, 1000, pool);
  thread t2(op2, 1000, pool);
  thread t3(op2, 1000, pool);
  thread t4(op2, 1000, pool);
  thread t5(op2, 1000, pool);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  chrono::steady_clock::time_point end = chrono::steady_clock::now();
  auto length = end - begin;
  std::cout << "连接池，多线程，用时" << length.count() / 1000000 << "毫秒"
            << std::endl;
}
int main() {
  test2();
  std::cout << "end" << std::endl;
  return 0;
}
} // namespace testStrangeThread
