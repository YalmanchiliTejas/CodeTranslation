#include <iostream>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;
  while (X > 0 || Y > 0) {
    if ((X != 0 && Y != 0) && (2 * C < A + B)) {
      ans += 2 * C;
      X--, Y--;
    } else if (X != 0 && Y != 0) {
      ans += A + B;
      X--, Y--;
    } else if (X > 0) {
      if (2 * C < A) {
        ans += 2 * C;
      } else {
        ans += A;
      }
      X--;
    } else {
      if (2 * C < B) {
        ans += 2 * C;
      } else {
        ans += B;
      }
      Y--;
    }
  }

  cout << ans << endl;

  return 0;
}