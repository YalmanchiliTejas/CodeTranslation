#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  rep(i, n) cin >> a[i];

  long long dp[n][n];
  rep(i, n) dp[i][i] = a[i];

  for (int i = n - 2; i > -1; --i) {
    for (int j = i + 1; j < n; ++j) {
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }
  cout << dp[0][n - 1] << endl;
}
