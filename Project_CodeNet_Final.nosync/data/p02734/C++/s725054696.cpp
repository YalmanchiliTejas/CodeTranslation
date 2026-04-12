#include <cstring>
#include <iostream>

#define MOD 998244353

using namespace std;

int n, s;
long long a[3043];
long long dp[3043][3043];
long long ans;

int main(int argc, char const *argv[]) {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; --i) {
    dp[i][a[i]] += n - i + 1;
    dp[i][a[i]] %= MOD;
    for (int j = 0; j <= s; ++j) {
      dp[i][j] += dp[i + 1][j];
      dp[i][j] %= MOD;
    }
    for (int j = a[i]; j <= s; ++j) {
      dp[i][j] += dp[i + 1][j - a[i]];
      dp[i][j] %= MOD;
    }
  }

  for (int i = 1; i <= n; ++i) {
    ans += dp[i][s];
    ans %= MOD;
  }

  cout << ans % MOD << endl;

  return 0;
}
