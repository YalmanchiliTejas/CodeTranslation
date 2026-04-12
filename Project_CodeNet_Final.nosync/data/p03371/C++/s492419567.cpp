#include<iostream>
using namespace std;
int main () {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int af = A * X + B * Y;
  int bf, cf;
  if (X > Y) {
    bf = 2 * C * Y + A * (X - Y);
    cf = 2 * C * X;
  }
  else {
    bf = 2 * C * X + B * (Y - X);
    cf = 2 * C * Y;
  }
  int ans = af;
  //cout << af << ' ' << bf << ' ' << cf << endl;
  if (ans > bf) ans = bf;
  if (ans > cf) ans = cf;
  cout << ans << endl;
}

