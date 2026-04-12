#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

/*
a[1]以上の全ての値について, a[i]*a[0..i-1]の累積和を求め, それらを足すと答えが出る.
詳しくは解説動画参照.
このとき, 計算過程で出た値や最終値がとても大きい場合があるので, mod10e9+7で小さくする.
ちなみに, 足し算, 引き算, 掛け算においては全ての計算が終わった後にあまりをとっても,
途中過程で逐一あまりをとっても最終的な値は変わらない.
例えば(a*b*c)%dと((a*b)%d)*cは同じ値を出力する.ただし引き算は要注意.
詳しくはdrkenさんの記事参照.
*/

const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  int ans = 0;
  int x = 0;
  rep(i, n) {
    ans = (ans + ((ll)a[i] * x)) % mod;
    x = (x + a[i]) % mod;
  }
  
  cout << ans << endl;
}