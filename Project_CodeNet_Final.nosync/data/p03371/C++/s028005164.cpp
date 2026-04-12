#include<bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (A + B < 2 * C) {
    cout << A * X + B * Y << endl;
  } else {
    int value = 2 * C * min(X, Y);
    if (X - Y > 0) {
      value += (X - Y) * min(2 * C, A);
    }
    if (Y - X > 0) {
      value += (Y - X) * min(2 * C, B);
    }
    cout << value << endl;
  }
  return 0;
}