#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = 1e18;
  for (int ab_cnt = 0; ab_cnt <= 200000; ab_cnt += 2) {  // ab 購入枚数
    int a_remain = max(0, x - ab_cnt / 2);               // a 残り枚数
    int b_remain = max(0, y - ab_cnt / 2);               // b 残り枚数
    ll cost = a_remain * a + b_remain * b + ab_cnt * c;
    ans = min(ans, cost);
  }
  cout << ans << endl;
}
