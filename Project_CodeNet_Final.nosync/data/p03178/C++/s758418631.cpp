#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
string K;
int D;

int dp[10010][2][110] = {0}; // dp[i桁目][K未満?][mod D] = 総数

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

  cout << (dp[n][0][0] + dp[n][1][0] - 1 + MOD) % MOD << endl;

  return 0;
}