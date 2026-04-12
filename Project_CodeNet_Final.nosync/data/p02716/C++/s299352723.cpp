#include <iostream>
using namespace std;
long long n, a[200010], dp[200010][2];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[i][0] = -1e18;
    dp[i][1] = -1e18;
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int j = (i - 1) / 2;
    dp[j + 1][0] = max(dp[j + 1][0], dp[j + 1][1]);
    dp[j + 1][1] = dp[j][0] + a[i - 1];

    dp[j][0] = max(dp[j][0], dp[j][1]);
    dp[j][1] = dp[j - 1][0] + a[i - 1];
  }
  cout << max(dp[n / 2][0], dp[n / 2][1]);
  return 0;
}

