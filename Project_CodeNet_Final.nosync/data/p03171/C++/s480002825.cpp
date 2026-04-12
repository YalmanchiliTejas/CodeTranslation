#include<iostream>
#include<vector>
using namespace std;

/*long long int f(int i, int j, vector<vector<bool>>& vis,
     vector<vector<long long int>>& dp, vector<int>& a)
{
  auto& ret = dp[i][j];
  if (vis[i][j])
    return ret;
  if (i == j)
    return a[i];
  vis[i][j] = true;

    return ret = max(a[i] - f(i + 1, j, vis, dp, a), a[j] - f(i, j - 1,  vis, dp,a));
}
*/


int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<vector<long long int>> dp(n, vector<long long int>(n));
  for (int i = 0; i < n; ++i)
    dp[i][i] = a[i];
  for (int len = 2; len <= n; ++len)
  {
    for (int i = 0; i + len - 1 < n; ++i)
    {
      int j = i + len - 1;
      dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
    }
  }

  cout << dp[0][n-1] << '\n';

  return 0;
}
