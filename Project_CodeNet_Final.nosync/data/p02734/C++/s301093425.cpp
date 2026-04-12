#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i=0; i<int(n); i++)
using V = vector<int>;
using VV = vector<V>;
const int MOD = 998244353;

int main() {
  int N, S; cin >> N >> S;
  V a(N);
  rep(i, N) cin >> a[i];

  V dp(S+1);
  int ans = 0;
  rep(r, N) {
    for (int s = S; s >= 0; --s) {
      if (s >= a[r]) dp[s] += dp[s-a[r]];
      if (s == a[r] || s == 0) ++dp[s];
      dp[s] %= MOD;
    }
    (ans += dp[S]) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
