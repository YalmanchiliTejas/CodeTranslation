#include <iostream>

int main() {
  unsigned long long N;
  unsigned long long result = 0, temp, sum = 0;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> temp;
    result += temp * sum;
    result %= 1000000007;
    sum += temp;
    sum %= 1000000007;
  }

  std::cout << result << std::endl;
}
