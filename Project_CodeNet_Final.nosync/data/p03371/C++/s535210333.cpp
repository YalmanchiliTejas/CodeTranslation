#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int price;
  if (A + B >= 2*C) {
    if (X > Y) {
      price += 2*C*Y;
      X -= Y;
      if (A >= 2*C) {
        price += 2*C*X;
      }
      else {
        price += A*X;
      }
    }
    else {
      price += 2*C*X;
      Y -= X;
      if (B >= 2*C) {
        price += 2*C*Y;
      }
      else {
        price += B*Y;
      }
    }
  }
  else {
    price += A*X + B*Y;
  }
  cout << price << endl;
}
