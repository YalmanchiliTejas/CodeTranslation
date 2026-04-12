/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　| 　_　 _ l
　 　　　／` ミ＿xノ
　　 　 /　　　 　 |　見ちゃだめだよ！
　　　 /　 ヽ　　 ﾉ　　
　 　 │　　|　|　|　　
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)__)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll mi = INF;
  for (int i = 0; i <= 200000; i++) {
    if (i % 2 == 1) continue;
    int newx, newy;
    if (x - i / 2 < 0)
      newx = 0;
    else
      newx = x - i / 2;
    if (y - i / 2 < 0)
      newy = 0;
    else
      newy = y - i / 2;
    ll total = i * c + a * newx + b * newy;
    mi = min(total, mi);
  }
  cout << mi << endl;
}