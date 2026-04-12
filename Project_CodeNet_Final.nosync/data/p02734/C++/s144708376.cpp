#include <iostream>
using namespace std;

const int64_t MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;
  int64_t dp[s + 1], result = 0;
  for (int i = 0; i <= s; ++i) {
    dp[i] = 0;
  }
  for (int a; cin >> a; ) {
    dp[0] += 1;
    for (int j = s; j > 0; --j) {
      if (j >= a) {
        dp[j] = (dp[j] + dp[j - a]) % MOD;
      }
    }
    result = (result + dp[s]) % MOD;
  }
  cout << result;
  return 0;
}
