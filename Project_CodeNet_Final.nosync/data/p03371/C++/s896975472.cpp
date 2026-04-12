#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans{};
  int t = min(X, Y);
  if (A + B < C * 2) {
    ans += (A + B) * t;
  } else {
    ans += C * 2 * t;
  }
  int XorY;
  int AorB;
  if (X > Y) {
    XorY = X - t;
    AorB = A;
  } else {
    XorY = Y - t;
    AorB = B;
  }
  if (AorB < C * 2) {
    ans += AorB * XorY;
  } else {
    ans += C * 2 * XorY;
  }

  cout << ans << endl;
  return 0;
}
