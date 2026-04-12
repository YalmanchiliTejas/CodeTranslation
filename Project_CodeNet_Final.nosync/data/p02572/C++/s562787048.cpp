#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

constexpr long mod = 1000000000 + 7;

long solve(int n, const std::vector<long>& values)
{
  long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum = (sum + values[i]) % mod;
  }

  long result = 0;
  for (int i = 0; i < n; ++i) {
    sum = (sum - values[i]) % mod;
    if (sum < 0) sum += mod;

    result = (result + (values[i] * sum) % mod) % mod;
  }

  return result;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<long> values(n);
  for (auto& v : values) {
    std::cin >> v;
  }

  std::cout << std::setprecision(20);
  std::cout << solve(n, values) << std::endl;
}
