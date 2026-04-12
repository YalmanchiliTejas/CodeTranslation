#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <limits>
#include <algorithm>
#include <memory>

constexpr long long MOD = 1000000007;

int main()
{
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;
  int K;
  std::cin >> K;
  char c = S[K-1];
  for (auto& val: S)
  {
    if (val != c)
      val = '*';
  }
  std::cout << S << std::endl;
  return 0;
}

