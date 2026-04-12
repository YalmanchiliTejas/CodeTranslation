#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int res = min(2 * min(X, Y) * C, min(X, Y) * A + min(X, Y) * B);
  int Z = max(X, Y) - min(X, Y);
  if (min(X, Y) == X) {
    res += min(2 * Z * C, Z * B);
  } else {
    res += min(2 * Z * C, Z * A);
  }
  cout << res << '\n';
  return 0;
}
