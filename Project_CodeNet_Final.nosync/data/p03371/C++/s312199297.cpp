#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;

  if (A + B > 2 * C) {
    int sub = min(X, Y);
    X -= sub;
    Y -= sub;
    ans += sub * 2 * C;

    if (X < Y) {
      if (B > 2 * C) {
        ans += Y * 2 * C;
      } else {
        ans += Y * B;
      }
    } else if (X > Y) {
      if (A > 2 * C) {
        ans += X * 2 * C;
      } else {
        ans += X * A;
      }
    }
    cout << ans << endl;
  } else {
    cout << A * X + B * Y << endl;
  }

  return 0;
}