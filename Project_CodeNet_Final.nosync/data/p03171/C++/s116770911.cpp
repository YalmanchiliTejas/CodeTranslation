#include <iostream>
#include <algorithm>

using namespace std;

#define N 3010

int main() {
  int32_t n;
  cin >> n;

  auto a = new int64_t[N];
  for (int32_t i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto dp = new int64_t[N][N];
  for (int32_t j = 0; j <= n; ++j) {
    dp[0][j] = 0;
  }
  for (int32_t i = 1; i <= n; ++i)
    for (int32_t j = 0; j <= n - i; ++j) {
      dp[i][j] = max(a[j+i-1] - dp[i-1][j], a[j] - dp[i-1][j+1]);
    }

  cout << dp[n][0] << endl;
}
