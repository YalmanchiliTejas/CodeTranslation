#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
const int MOD = 998244353;

int n, s;
int a[N];

int dp[N][N];
int f(int x, int sum) {
  if (sum == 0) return x+2;
  if (x < 0 || sum < 0) return 0;
  if (~dp[x][sum]) return dp[x][sum];

  return dp[x][sum] = (f(x-1, sum) + f(x-1, sum - a[x])) % MOD;
}

int solve() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // cerr << f(i, s) << endl;
    ans = (ans + 1LL * f(i-1, s-a[i]) * (n-i)) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}
