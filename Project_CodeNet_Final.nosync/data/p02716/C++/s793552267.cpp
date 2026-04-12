#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 1) {
      a[i] += a[i - 2];
    }
  }
  vector<long long> dp(n);
  for (int i = 1; i < n; i++) {
    if (i & 1) {
      dp[i] = a[i - 1];
    } else {
      dp[i] = dp[i - 1];
    }
    if (i > 1) {
      dp[i] = max(dp[i], dp[i - 2] + a[i] - a[i - 2]);
    } else {
      dp[i] = max(dp[i], a[i]);
    }
  }
  cout << dp[n - 1] << '\n';
  return 0;
}