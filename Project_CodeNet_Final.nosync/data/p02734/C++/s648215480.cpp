#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
using V = vector<int>;
using VV = vector<V>;
const int MOD = 998244353;

int main() {
  int N, S; cin >> N >> S;
  V a(N);
  rep(i, N) cin >> a[i];

  VV dp(N+1, V(S+1));
  rep(r, N+1) dp[r][0] = r;

  rep(r, N) rep2(s, 1, S+1) {
    dp[r+1][s] = dp[r][s];
    dp[r+1][s] += (s >= a[r]) ? dp[r][s-a[r]] : 0;
    dp[r+1][s] += (s == a[r]) ? 1 : 0;
    dp[r+1][s] %= MOD;
  }

  int ans = 0;
  rep(r, N) (ans += dp[r+1][S]) %= MOD;
  cout << ans << endl;
  return 0;
}
