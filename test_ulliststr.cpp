#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  list.push_back("V");
  std::cout << "Front: " << list.front() << " Back: "
  << list.back() << " Size: " << list.size() << std::endl;

  list.push_front("I");
  std::cout << "Front: " << list.front() << " Back: "
  << list.back() << " Size: " << list.size() << std::endl;

  list.pop_back();
  std::cout << "Back: " << list.back() << " Size: " << list.size() << std::endl;

  list.pop_front();
  std::cout << "Empty list " << list.empty() << std::endl;

  list.push_back("H");
  list.set(0, "E");
  std::cout << "Val at 0 " << list.get(0) << std::endl;

  list.clear();
  std::cout << "Empty list " << list.empty() << std::endl;

  return 0;
}
