#include <algorithm>
#include <iostream>

using namespace std;

const long long INF = 1e17;

long long dp[200200][3][2];

int main() {
  int n; cin >> n;
  int a[200000]; for (int i = 0; i < n; ++i) cin >> a[i];
  
  if (n % 2 == 0) {
    long long mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) if (i % 2 == 0) sum += a[i];
    mx = sum;
    for (int i = n-2; i >= 0; --i) if (i % 2 == 0) {
      sum += a[i+1] - a[i];
      mx = max(mx, sum);
    }
    cout << mx << endl;
    return 0;
  }
  
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 2; ++k) dp[i][j][k] = -INF;
  
  dp[0][0][0] = 0;
  
  for (int i = 0; i < n-1; ++i) for (int j = 0; j < 3; ++j) {
    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][1]);
    dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] + a[i]);
    if (j > 0) dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j-1][0]);
  }
  
  long long ans = dp[n-1][2][0] + a[n-1];
  for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k)
    ans = max(ans, dp[n-1][j][k]);
  
  cout << ans << endl;
  return 0;
}