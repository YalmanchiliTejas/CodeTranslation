#include <iostream>
#include <vector>
#include <cstdint>

int main() {
  constexpr std::int64_t kModulus = 1000000007;
  int N;
  std::cin >> N;
  std::vector<std::int64_t> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  std::int64_t sum = 0;
  std::int64_t sum_products = 0;
  for (int i = 0; i < N; ++i) {
    sum_products = (sum_products + sum * A[i]) % kModulus;
    sum = (sum + A[i]) % kModulus;
  }
  std::cout << sum_products << std::endl;
  return 0;
}
