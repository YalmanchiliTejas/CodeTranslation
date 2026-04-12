#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans{};
  if (A + B > C * 2) {
    int Z = min(X, Y);
    ans += C * Z * 2;
    X -= Z;
    Y -= Z;
  }
  if (X > 0) {
    if (A > C * 2) {
      ans += C * X * 2;
      Y -= X;
    } else {
      ans += A * X;
    }
  }
  if (Y > 0) {
    if (B > C * 2) {
      ans += C * Y * 2;
    } else {
      ans += B * Y;
    }
  }

  cout << ans << endl;
  return 0;
}
