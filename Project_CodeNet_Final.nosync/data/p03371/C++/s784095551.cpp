#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long cost;
  if (A + B > C * 2) {
    cost = min(X, Y) * 2 * C;
    int D = X > Y ? A : B;
    int r = abs(X - Y);
    if (D > C * 2) {
      cost += r * C * 2;
    } else {
      cost += r * D;
    }
  } else {
    cost = A * X + B * Y;
  }
  cout << cost << endl;

  return 0;
}
/* vim:set fdm=marker: */
