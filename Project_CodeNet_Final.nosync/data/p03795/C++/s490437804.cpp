#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int back = N / 15;
  int pay = 800 * N - 200 * back;
  std::cout << pay << std::endl;

  return 0;
}
