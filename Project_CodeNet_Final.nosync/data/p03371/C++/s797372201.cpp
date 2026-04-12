#include <iostream>

using namespace std;

int main() {
  int A, B, C, X, Y, ans{};
  cin >> A >> B >> C >> X >> Y;

  if (A >= 2 * C) {
    while (X > 0) {
      ans += C * 2;
      --X, --Y;
    }
  }
  if (B >= 2 * C) {
    while (Y > 0) {
      ans += C * 2;
      --X, --Y;
    }
  }
  if (A + B > 2 * C) {
    while (X > 0 && Y > 0) {
      ans += C * 2;
      --X, --Y;
    }
  }
  while (X > 0) {
    ans += A;
    --X;
  }
  while (Y > 0) {
    ans += B;
    --Y;
  }
  cout << ans << endl;
}
