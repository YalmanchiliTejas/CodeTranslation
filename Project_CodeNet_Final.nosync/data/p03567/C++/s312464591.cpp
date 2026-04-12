#include <stdint.h>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::string s;
  std::cin >> s;
  if (s.find("AC") != std::string::npos)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
