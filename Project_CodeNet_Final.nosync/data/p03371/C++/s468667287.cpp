#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int Z = min(X, Y);
  int ans = 0;
  if (Z * (A + B) > Z * 2 * C) {
    ans += (Z * 2 * C);
  }
  else {
    ans += (Z * (A + B));
  }
  if (X < Y) {
    if ((Y - X) * B < (Y - X) * 2 * C) {
      ans += ((Y - X) * B);
    }
    else {
      ans += ((Y - X) * 2 * C);
    }
  }
  else {
    if ((X - Z) * A < (X - Z) * 2 * C) {
      ans += ((X - Z) * A);
    }
    else {
      ans += ((X - Z) * 2 * C);
    }
  }
  cout << ans << endl;
}