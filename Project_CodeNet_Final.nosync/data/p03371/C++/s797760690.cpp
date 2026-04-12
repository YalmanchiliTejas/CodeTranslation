#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y, ans;
  cin >> A >> B >> C >> X >> Y;
  if (A + B <= 2 * C) {
    ans = A * X + B * Y;
  }
  else if (X >= Y && A <= 2 * C) {
    ans = C * 2 * Y + A * (X - Y);
  }
  else if (X < Y && B <= 2 * C) {
    ans = C * 2 * X + B * (Y - X);
  }
  else if (X >= Y && A > 2 * C) {
    ans = C * 2 * X;
  }
  else if (X < Y && B > 2 * C) {
    ans = C * 2 * Y;
  }
  cout << ans << endl;
}