#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> ac(n + 1);
  ac[0] = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[i] = tmp;
    ac[i + 1] = ac[i] + tmp;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 0;
  }
  for (int dif = 1; dif <= n; dif++) {
    for (int i = 0; i + dif <= n; i++) {
      int j = i + dif;
      dp[i][j] = ac[j] - ac[i] - min(dp[i][j - 1], dp[i + 1][j]);
    }
  }
  long long ans = 2 * dp[0][n] - (ac[n] - ac[0]);
  cout << ans << '\n';
  return 0;
}