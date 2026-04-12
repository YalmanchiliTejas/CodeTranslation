#include <bits/stdc++.h>

using namespace std;

int n;
long long v[3002];
long long dp[3002][3002];

void calc(int l,int r) {
  if(dp[l][r] != -1) return;
  calc(l + 1, r);
  calc(l, r - 1);
  long long x = v[l] - dp[l + 1][r];
  long long y = v[r] - dp[l][r - 1];
  dp[l][r] = max(x, y);
}

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1; i <= n;i++) {
    for(int j =1; j <= n; j++)
      dp[i][j] = -1;
  }
  for(int i = 1; i <= n; i++) {
    dp[i][i] = v[i];
  }
  calc(1, n);
  cout << dp[1][n];
  return 0;
}
