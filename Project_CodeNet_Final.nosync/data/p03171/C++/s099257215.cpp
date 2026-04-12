#include <bits/stdc++.h>
using namespace std;
 
long long dp[3010][3010];
int a[3010];
 
void solve()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  
  for (int len = 2; len <= n; len++)
  {
    for (int i = 0; i + len - 1 < n; i++)
    {
      int j = i + len - 1;
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }
  
  if (n % 2 == 1) cout << dp[0][n - 1] << endl;
  else cout << dp[0][n - 1] << endl;
}
 
int main()
{
  solve();
  return 0;
}