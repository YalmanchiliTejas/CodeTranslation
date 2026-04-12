#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // dp[l][r] := [l, r) から開始したときの X-Y の得点
  vector<vector<long long>> dp(n + 10, vector<long long>(n + 10, 0));
  // 区間が短い順に埋める
  for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      int r = l + len;
      // First
      if (len % 2 == n % 2) {
        dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
      } else { // second
        dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
      }
    }
  }
  cout << dp[0][n] << endl;

  return 0;
}