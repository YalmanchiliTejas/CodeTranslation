#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<int> A(N);
  
  for(auto& e : A)
  {
    cin >> e;
  }
  
  vector<vector<int64_t> > dp(N, vector<int64_t>(N, 0));
  
  for(int i = 0; i < N; ++i)
  {
    dp[i][i] = A[i];
  }
  
  for(int dist = 2; dist <= N; ++dist)
  {
    for(int L = 0, R = dist - L - 1; R < N; ++L, ++R)
    {
      dp[L][R] = max(A[L] - dp[L + 1][R], A[R] - dp[L][R - 1]);
    }
  }
  
  int64_t res = dp[0][N - 1];
  
  cout << res << "\n";
  
  return 0;
}