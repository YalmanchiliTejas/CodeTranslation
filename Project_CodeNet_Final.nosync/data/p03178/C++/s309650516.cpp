#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
string K;
int D;

int dp[10010][2][110] = {0};

signed main() {
  cin >> K >> D;
  int n = K.size();

  dp[0][0][0] = 1;
  for (int digit = 0; digit < n; digit++) {
    for (int smaller : {0, 1}) {
      int lim = smaller == 1 ? 9 : K[digit] - '0';
      for (int num = 0; num <= lim; num++) {
        for (int modD = 0; modD < D; modD++) {
          dp[digit+1][smaller || num < lim][(modD + num) % D] += dp[digit][smaller][modD] % MOD;
        }
      }
    }
  }

  // この部分
  int ans = 0;
  for (int smaller : {0, 1}) {
    ans = ((ans % MOD) + (dp[n][smaller][0] % MOD)) % MOD;
  }
  ans = ((ans % MOD) + ((-1 + MOD) % MOD)) % MOD;
  cout << ans << endl;

  return 0;
}
