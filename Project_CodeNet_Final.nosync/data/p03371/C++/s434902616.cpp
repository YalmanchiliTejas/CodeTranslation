#include <iostream>
using namespace std;
int main() {
  int A, B, C, X, Y, r;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;
  if ((A + B) < C) {
    if (X < Y) {
      r = (A + B) * X;
      r += (B < C ? B : C) * (Y - X);
    } else {
      r = (A + B) * Y;
      r += (A < C ? A : C) * (X - Y);
    }
  } else {
    if (X < Y) {
      r = C * X;
      r += (B < C ? B : C) * (Y - X);
    } else {
      r = C * Y;
      r += (A < C ? A : C) * (X - Y);
    }
  }
  cout << r << endl;
  return 0;
}
