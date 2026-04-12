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
#include <cassert>

//std::cout << std::fixed << std::setprecision(10)
//std::ios::sync_with_stdio(false);
//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};

int main()
{
  int N, S;
  std::cin >> N >> S;
  std::vector<int> A(N);
  for(auto& val:A)
    std::cin >> val;
  std::vector<std::vector<long long>> dp1(N, std::vector<long long>(S + 1, 0));
  std::vector<std::vector<long long>> dp2(N, std::vector<long long>(S + 1, 0));
  if(A[0] <= S)
  {
    dp1[0][A[0]] = 1;
    dp2[0][A[0]] = 1;
  }
  for(int i = 1; i < N; ++i)
  {
    for(int s = 1; s <= S; ++s)
    {
      dp1[i][s] = dp1[i-1][s];
      auto x = s-A[i];
      if(0<x&&x<=S)
        dp1[i][s] += dp1[i-1][x];
      dp1[i][s] %= MOD;
      if(s==A[i])
        dp1[i][s] += i+1;
      dp1[i][s] %= MOD;
      dp2[i][s] = (dp2[i-1][s]+dp1[i][s])%MOD;
    }
  }
  std::cout << dp2.back().back() << std::endl;
  return 0;
}

