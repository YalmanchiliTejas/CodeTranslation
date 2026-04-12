#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long ans = 1e9;
  for (int i = 0; i <= max(X, Y); i++) {
    long cost = i * C * 2;
    long x = i;
    long y = i;
    if (x < X) cost += A * (X - x);
    if (y < Y) cost += B * (Y - y);
    ans = min(ans, cost);
  }
  cout << ans << "\n";
}