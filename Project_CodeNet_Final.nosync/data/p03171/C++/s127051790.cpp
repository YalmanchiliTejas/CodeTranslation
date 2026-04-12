#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[i][i] = a[i];
  }

  for (int l = 2; l <= n; ++l) {
    for (int i = n - l; i >= 0; --i) {
      int r = i + l - 1;
      dp[i][r] = max(a[i] - dp[i + 1][r], a[r] - dp[i][r - 1]);
    }
  }

  cout << dp[0][n - 1] << '\n';

  return 0;
}
