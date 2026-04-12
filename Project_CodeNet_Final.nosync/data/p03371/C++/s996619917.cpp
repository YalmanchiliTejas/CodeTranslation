#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int a = A * X + B * Y;
  int b = 2 * C * max(X, Y);
  int c;
  if (X > Y) {
    c = 2 * C * Y + A * (X - Y);
  } else {
    c = 2 * C * X + B * (Y - X);
  }
  int ans = min({a, b, c});
  
  cout << ans << endl;
  
  
}