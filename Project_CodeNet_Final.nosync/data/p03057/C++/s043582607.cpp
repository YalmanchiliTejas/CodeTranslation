#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;
const int md = 1e9 + 7;

int dp[N];

signed main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> y;
  for (int i = 0; i < m; i++) {
    int cnt = 1;
    while (i + 1 < m && s[i + 1] == s[i]) {
      ++i;
      ++cnt;
    }
    y.push_back(cnt);
  }
  if (y.size() == 1) {
    vector<int> f(N), g(N);
    f[1] = 2, f[2] = 3;
    for (int i = 3; i <= n; i++) {
      f[i] = (f[i - 1] + f[i - 2]) % md;
    }
    g[2] = 3, g[3] = 4;
    for (int i = 4; i <= n; i++) {
      g[i] = (f[i - 1] + f[i - 3]) % md;
    }
    cout << g[n] << '\n';
    return 0;
  } else if (n % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }
  y.pop_back();
  int C = y[0] + 1;
  bool is = true;
  for (int x : y) {
    if (is && (x % 2 == 1)) {
      C = min(C, x);
    }
    is ^= 1;
  }
  dp[0] = dp[2] = 1;
  for (int i = 4; i < N; i += 2) {
    dp[i] = 2 * dp[i - 2] % md;
    if (i - 3 - C >= 0) {
      (dp[i] += md - dp[i - 3 - C]) %= md;
    }
  }
  int ans = dp[n];
  for (int l = 1; l <= C; l += 2) {
    if (n - l - 1 >= 0) {
      (ans += l * dp[n - l - 1] % md) %= md;
    }
  }
  ((ans %= md) += md) %= md;
  cout << ans << '\n';
  return 0;
}
