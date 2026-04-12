#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3010;
const int MOD = 998244353;

int n, s, a[N];
ll dp[3][N][N];

ll DP(int ty, int i, int sum) {
  if(i < 1) return sum == 0;
  if(dp[ty][i][sum] != -1) return dp[ty][i][sum];

  if(ty == 2) {
    dp[2][i][sum] = DP(2, i - 1, sum) + DP(1, i, sum);
    if(dp[2][i][sum] >= MOD) dp[2][i][sum] -= MOD;
  } else if(ty == 1) {
    dp[1][i][sum] = DP(1, i - 1, sum);
    if(sum - a[i] >= 0) dp[1][i][sum] += DP(1, i - 1, sum - a[i]);
    if(dp[1][i][sum] >= MOD) dp[1][i][sum] -= MOD;
    dp[1][i][sum] += DP(0, i, sum);
    if(dp[1][i][sum] >= MOD) dp[1][i][sum] -= MOD;
  } else {
    dp[0][i][sum] = DP(0, i - 1, sum);
  }
  return dp[ty][i][sum];
}

int main () {
  scanf("%d %d", &n, &s);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", DP(2, n, s));
  return 0;
}