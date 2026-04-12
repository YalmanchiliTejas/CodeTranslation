#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  if (X > Y) {
    swap(X, Y);
    swap(A, B);
  }
  C *= 2;

  int ans = 0;
  if (A + B > C) {
    ans += C * X;
    if (B > C) ans += C * (Y - X);
    else ans += B * (Y - X);
  } else {
    ans += A * X + B * Y;
  }

  cout << ans << endl;
}