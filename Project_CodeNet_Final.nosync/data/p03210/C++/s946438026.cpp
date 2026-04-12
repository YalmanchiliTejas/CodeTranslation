#include <iostream>

int main() {
  int inp;
  std::cin >> inp;
  if(inp == 3 || inp == 5 || inp == 7) {
  	std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
  return 0;
}