#include <iostream>

int main() {
  long long N = 0;
  std::cin >> N;
  
  std::cout << (N * 800) - ((N / 15) * 200) << std::endl;
}