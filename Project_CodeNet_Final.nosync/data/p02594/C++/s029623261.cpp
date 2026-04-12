#include <iostream>

int main(void) {
  int x;
  std::cin >> x;
  if (x < 30) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
  }

  return 0;
}
