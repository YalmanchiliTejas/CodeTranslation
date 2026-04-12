#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
#define _GLIBCXX_DEBUG
     
int main() {
  int val_a, val_b, val_c, want_x, want_y;
  cin >> val_a >> val_b >> val_c >> want_x >> want_y;

  int a=0, b=0, c=max(want_x, want_y) * 2;
  ll ans = c * val_c;
  for (--c; c>=0; --c) {
    if (want_x > a + c / 2) ++a;
    if (want_y > b + c / 2) ++b;
    if (ans > a * val_a + b * val_b + c * val_c) {
      ans = a * val_a + b * val_b + c * val_c;
    }
  }
  cout << ans << endl;
}