#include<iostream>
#include<vector>
using namespace std;

long long int f(int i, int j, vector<vector<bool>>& vis,
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



int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<vector<bool>> vis(n, vector<bool>(n));
  vector<vector<long long int>> dp(n, vector<long long int>(n));
  cout << f (0, n-1, vis, dp, a) << '\n';

  return 0;
}
