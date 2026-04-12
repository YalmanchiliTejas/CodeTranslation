#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
#define MOD 1000000007

template <class T> void add(T &a, T b) { a = (a + b) % MOD; }
ll dp[10005][2][105];

int main() {
  string K;
  int D;
  cin >> K >> D;
  int N = K.size();
  dp[0][0][0] = 1;
  rep(i, N) rep(j, 2) rep(k, D) {
    int x = j ? 9 : K[i] - '0';
    rep(d, x + 1) add(dp[i + 1][j || d < x][(k + d) % D], dp[i][j][k]);
  }
  ll ans = dp[N][0][0] + dp[N][1][0] - 1;
  if (ans < 0)
    ans += MOD;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
