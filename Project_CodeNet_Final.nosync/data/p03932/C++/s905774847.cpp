#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int mf(const int& a, const int& b, const int& c, const int& d) {
  return max(a, max(b, max(c, d)));
}
int main() {
  int n, m;
  cin >> n >> m;
  int mp[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> mp[i][j];
  int dp[n][m][n] = {};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = max(0, i + j - m + 1); k < min(i + j + 1, n); ++k) {
        dp[i][j][k] = mf(i ? dp[i-1][j][k] : 0,
                         j ? dp[i][j-1][k] : 0,
                         i && k ? dp[i-1][j][k-1] : 0,
                         j && k ? dp[i][j-1][k-1] : 0)
                        + mp[i][j] + (i == k ? 0 : mp[k][i+j-k]);
      }
    }
  }
  cout << dp[n-1][m-1][n-1] << '\n';
  return 0;
}