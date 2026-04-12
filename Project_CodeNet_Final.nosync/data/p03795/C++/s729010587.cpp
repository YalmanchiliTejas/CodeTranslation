#include <iostream>

int main() {
  int N;
  std::cin >> N;
  std::cout << (800 * N - 200 * (N / 15)) << '\n';
  return 0;
}
