#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353LL

using namespace std;

int main() {
  int n, s;
  ll o = 0;
  scanf("%d %d", &n, &s);
  vector<vector<ll>> dp(n + 1, vector<ll>(s + 1));
  vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= s; j++) {
      dp[i + 1][j] += dp[i][j];
      if(j - a[i] >= 0) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]]) % MOD;
    }
    dp[i + 1][0]++;
    o = (o + dp[i + 1][s]) % MOD;
  }
  printf("%lld\n", o);
}