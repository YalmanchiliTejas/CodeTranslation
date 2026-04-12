#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//std::cout << std::fixed << std::setprecision(10)
constexpr long long MOD = 1000000007;

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto& val: A)
    std::cin >> val;
  auto solve = [&]()
  {
    std::multiset<int> tails;
    tails.insert(A[0]);
    for (int i = 1; i < A.size(); ++i)
    {
      auto val = A[i];
      auto it = tails.lower_bound(val);
      if (it == tails.begin())
      {
        tails.insert(val);
      }
      else
      {
        --it;
        tails.erase(it);
        tails.insert(val);
      }
    }
    return tails.size();
  };
  std::cout << solve() << std::endl;
  return 0;
}

