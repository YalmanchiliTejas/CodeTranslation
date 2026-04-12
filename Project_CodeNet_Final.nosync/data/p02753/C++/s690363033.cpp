#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  if (s == "AAA" || s == "BBB")
    std::cout << "No\n";
  else {
    std::cout << "Yes\n";
  }
  return 0;
  }
