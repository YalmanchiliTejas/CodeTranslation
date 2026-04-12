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

int rec(int digit, int smaller, int modD) {
  // 桁を超えたら終了
  if (digit >= K.size()) {
    return modD == 0;
  }

  // メモした値なら返す
  if (dp[digit][smaller][modD] != -1) {
    return dp[digit][smaller][modD];
  }

  int lim = (smaller ? 9 : K[digit] - '0'); // 上限値
  int ret = 0;
  for (int num = 0; num <= lim; num++) {
    int t = rec(digit + 1, smaller || (num < lim), (modD + num) % D);
    Add(ret, t);
  }

  return dp[digit][smaller][modD] = ret; // ここでメモ
}

signed main() {
  cin >> K >> D;

  // DPテーブルを初期化
  for (int i = 0; i < 11111; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 111; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  int ans = rec(0, 0, 0); // メモ化再帰に投げる
  Add(ans, -1LL); // 0になる場合の数を引く
  cout << ans << endl;

  return 0;
}