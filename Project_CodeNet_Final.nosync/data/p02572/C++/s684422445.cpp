#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const uint64_t mod = 1'000'000'000 + 7;

int main() {
  uint32_t N = 0;
  std::cin >> N;

  uint64_t sum = 0, sq_sum = 0;
  for (size_t i = 0; i < N; i++)
  {
    uint64_t a = 0;
    std::cin >> a;

    sum += a;
    sq_sum += (a*a) % mod;
    sum %= mod;
    sq_sum %= mod;
  }
  
  uint64_t result = (sum*sum) % mod;
  result += (result < sq_sum ? mod : 0);
  result -= sq_sum;

  result *= (mod+1)/2;
  result %= mod;

  std::cout << result << std::endl;

  return 0;
}