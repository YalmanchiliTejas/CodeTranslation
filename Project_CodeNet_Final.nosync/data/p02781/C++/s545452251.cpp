#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<vector<int>> dp(2, vector<int>(k + 1));
  dp[1][0] = 1;
  for (char c : s) {
    vector<vector<int>> ndp(2, vector<int>(k + 1));
    for (int f : {0, 1}) {
      for (int i = 0; i <= k; ++i) {
        for (int d = 0; d < 10; ++d) {
          if (f and d > (c - '0')) {
            continue;
          }
          if (d and i == k) {
            continue;
          }
          ndp[f and d == (c - '0')][i + !!d] += dp[f][i];
        }
      }
    }
    swap(dp, ndp);
  }
  cout << dp[0][k] + dp[1][k] << '\n';
}
