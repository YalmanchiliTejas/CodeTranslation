#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int P1, P2, P3;
  P1 = A * X + B * Y;
  P2 = 2 * C * (max(X, Y));
  if (X > Y) P3 = 2 * C * Y + A * (X - Y);
  else P3 = 2 * C * X + B * (Y - X);
  cout << min(min(P1, P2), P3) << endl;
}
