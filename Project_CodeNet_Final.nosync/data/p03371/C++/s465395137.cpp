#include <bits/stdc++.h>

using namespace std;

template <typename T> T gcd(T x, T y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

template <typename T> T lcm(T x, T y) {
  if (x == 0 || y == 0)
    return 0;
  return x / gcd(x, y) * y;
}

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;

  long ans = 0;
  if (A + B > C) {
    int m = min(X, Y);
    ans += C * m;
    X -= m;
    Y -= m;
  }
  ans += min(A, C) * X;
  ans += min(B, C) * Y;
  cout << ans << endl;
}
