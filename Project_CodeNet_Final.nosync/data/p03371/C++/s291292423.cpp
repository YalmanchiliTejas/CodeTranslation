#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, C, X, Y;

int main() {
  cin >> A >> B >> C >> X >> Y;

  bool ac = false;
  if ((C * 2) < A) { ac = true; }
  bool bc = false;
  if ((C * 2) < B) { bc = true; }

  bool abc = false;
  if (!ac && !bc) {
    if (A + B > C * 2) { abc = true; }
  }

  ll c = (C * 2);
  if (ac && bc) {
    cout << (X > Y ? c * X : c * Y) << endl;
  } else if (ac) {
    if (X > Y) {
      cout << c * X << endl;
    } else {
      ll y = Y - X;
      cout << c * X + B * y << endl;
    }
  } else if (bc) {
    if (X > Y) {
      ll x = X - Y;
      cout << A * x + c * Y << endl;
    } else {
      cout << c * Y << endl;
    }
  } else {
    if (abc) {
      if (X > Y) {
        ll sum = c * Y;
        ll x   = X - Y;
        cout << sum + (x * A) << endl;
      } else {
        ll sum = c * X;
        ll y   = Y - X;
        cout << sum + (y * B) << endl;
      }
    } else {
      cout << A * X + B * Y << endl;
    }
  }
}