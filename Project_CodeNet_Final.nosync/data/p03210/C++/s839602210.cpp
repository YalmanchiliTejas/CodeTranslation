#include <iostream>

int main() {
  int X;
  std::cin >> X;
  if(X == 3 || X == 5 | X == 7)
    std::cout << "YES";
  else
    std::cout << "NO";
  return 0;
}