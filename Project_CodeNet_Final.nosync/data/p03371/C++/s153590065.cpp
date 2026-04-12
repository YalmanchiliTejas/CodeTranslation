#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int c1 = A * X + B * Y;
  int c2 = (X > Y) ? A * (X - Y) + 2 * C * Y : B * (Y - X) + 2 * C * X;
  int c3 = (X > Y) ? 2 * C * X : 2 * C * Y;
  cout << min({c1, c2, c3}) << endl;
}