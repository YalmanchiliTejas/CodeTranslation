#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T>void chmod(T &a, const T &b, const T &mod) {
  int ret = (a % mod) + (b % mod);
  if (ret < 0) {
    ret += mod;
  }
  a = ret;
}

const int MOD = 1e9 + 7;
string K;
int D;

int dp[10010][2][110] = {0};

signed main() {
  cin >> K >> D;
  int n = K.size();

  dp[0][0][0] = 1;
  for (int digit = 0; digit < n; digit++) { // 上からdigit桁目
    for (int smaller : {0, 1}) {
      int lim = smaller == 1 ? 9 : K[digit] - '0'; // この桁の上限値
      for (int num = 0; num <= lim; num++) {
        for (int modD = 0; modD < D; modD++) {
          chmod(dp[digit+1][smaller || num < lim][(modD + num) % D], dp[digit][smaller][modD], MOD);
        }
      }
    }
  }

  // この部分
  int ans = 0;
  for (int smaller : {0, 1}) {
    chmod(ans, dp[n][smaller][0], MOD);
  }
  chmod(ans, -1LL, MOD);
  cout << ans << endl;

  return 0;
}
