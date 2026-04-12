#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<long>> dp1(n, vector<long>(n, 0)),
      dp2(n, vector<long>(n, 0));  // dp1:先手の得点, dp2:後手の得点
  for (int i = 0; i < n; i++) dp1[i][i] = a[i];
  for (int d = 1; d < n; d++) {
    // d=r-l;
    for (int l = 0; l < n - d; l++) {
      int r = l + d;
      long x1 = a[l] + dp2[l + 1][r], y1 = dp1[l + 1][r],
           x2 = a[r] + dp2[l][r - 1], y2 = dp1[l][r - 1];
      if (x1 - y1 >= x2 - y2) {
        dp1[l][r] = x1;
        dp2[l][r] = y1;
      } else {
        dp1[l][r] = x2;
        dp2[l][r] = y2;
      }
    }
  }
  cout << dp1[0][n - 1] - dp2[0][n - 1];
  return 0;
}