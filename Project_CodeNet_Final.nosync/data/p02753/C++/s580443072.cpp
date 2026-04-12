#include <iostream>
int main(int argc, char *argv[]) {
  char S;
  bool A = false, B = false;
  while (std::cin >> S) {
    if (S == 'A')
      A = true;
    if (S == 'B')
      B = true;
    if (A && B) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
}
