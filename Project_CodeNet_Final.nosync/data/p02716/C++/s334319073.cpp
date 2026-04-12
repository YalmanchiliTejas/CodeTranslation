#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  const int MAX_N = 200010;
  vector<vector<ll>> dp(MAX_N, vector<ll>(3, -1e15));
  vector<ll> a(MAX_N);
  int n;
  cin >> n;
  const int offset = 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = -1; i <= 1; i++) {
    int index = 2 * 1 + i;
    dp[1][i + offset] = a[index];
  }
  for (int i = 1; i < n; i++) {
    for (int j = -1; j <= 1; j++) {
      for (int k = -1; k <= 1; k++) {
        int cur = 2 * i + j, nxt = 2 * (i + 1) + k;
        if (nxt <= cur + 1) continue;
        if (n < nxt) continue;
        dp[i + 1][k + offset] =
            max(dp[i + 1][k + offset], dp[i][j + offset] + a[nxt]);
      }
    }
  }
  cout << max({dp[n / 2][0], dp[n / 2][1], dp[n / 2][2]}) << endl;
}
