#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  vector<long long> v;
  vector<vector<long long>> dp;
  vector<long long> dp2;

  std::cin >> N;
  v.resize(N);
  dp = vector<vector<long long>>(N, vector<long long>(N, 0));

  for (int i = 0; i < N; ++i)
  { 
    long long val;
    cin >> val;
    v[i] = val;
  }

  for (int i = N-1; i >= 0; --i)
  {
    for (int j = i; j < N; ++j)
    {   
      if (i == j) { dp[i][j] = v[i]; continue; }
      long long a = v[i] - dp[i+1][j];
      long long b = v[j] - dp[i][j-1];
      dp[i][j] = max(a, b); 
    }   
  }

  std::cout << dp[0][N-1];

  return 0;
}