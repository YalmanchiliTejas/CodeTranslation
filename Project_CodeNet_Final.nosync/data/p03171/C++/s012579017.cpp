#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  rep(i, n)
  {
    cin >> a[i];
    if (n % 2 == 1)
      dp[i][i] = a[i];
    else
      dp[i][i] = -a[i];
  }
  for (int l = 1; l < n; l++)
    rep(i, n - l)
      if (l % 2 != n % 2)
        dp[i][i+l] = max(a[i] + dp[i+1][i+l], a[i+l] + dp[i][i+l-1]);
      else
        dp[i][i+l] = min(-a[i] + dp[i+1][i+l], -a[i+l] + dp[i][i+l-1]);
  cout <<  dp[0][n-1] << endl;
  return 0;
}