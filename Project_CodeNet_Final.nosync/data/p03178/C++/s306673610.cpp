#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T>
void Add(T &a, const T &b, const T &mod=1000000007) {
  int val = ((a % mod) + (b % mod)) % mod;
  if (val < 0) { val += mod; }
  a = val;
}

// ------------------------------------------------------------------------------------------

string K;
int D;
int dp[11111][2][111]; // dp[i桁目][未満フラグ][mod Dした値] = 総数

signed main() {
  cin >> K >> D;

  dp[0][0][0] = 1; // 初期化
  // DP
  for (int digit = 0; digit < K.size(); digit++) {
    for (int smaller : {0, 1}) {
      for (int modD = 0; modD < D; modD++) {
        int lim = (smaller ? 9 : K[digit] - '0');
        for (int num = 0; num <= lim; num++) {
          int nSmaller = smaller || (num < lim);
          Add(dp[digit+1][nSmaller][(modD + num) % D], dp[digit][smaller][modD]);
        }
      }
    }
  }

  int ans = 0;
  for (int smaller : {0, 1}) {
    Add(ans, dp[K.size()][smaller][0]);
  }

  Add(ans, -1LL); // 0になる場合の数を引く
  cout << ans << endl;

  return 0;
}