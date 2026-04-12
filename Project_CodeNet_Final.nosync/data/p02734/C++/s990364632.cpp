#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll mod = 998244353;
  int n,s;
  cin >> n >> s;
  vector<vector<ll>> dp;
  dp.assign(n+2,vector<ll>(s+10,0));
  ll ans = 0;
  rep(i,0,n) {
    int a;
    cin >> a;
    rep(j,0,s+1) {
      if (j == 0) {
        if (j+a <= s) {
          dp[i+1][j+a] += i+1;
          dp[i+1][j+a] %= mod;
        }
      } else if (0 < j && j < s) {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= mod;
        if (j+a <= s) {
          dp[i+1][j+a] += dp[i][j];
          dp[i+1][j+a] %= mod;
        }
      } else {
        ans += dp[i][s] * (n-i+1);
        ans %= mod;
      }
    }
  }
  ans += dp[n][s];
  ans %= mod;
  printf("%lld\n", ans);
  return 0;
}
