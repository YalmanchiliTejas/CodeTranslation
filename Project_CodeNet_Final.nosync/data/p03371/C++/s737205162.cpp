#include <bits/stdc++.h>
using namespace std;

int main() {

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  long sum = 0;

  if ((C * 2) <= (A + B)) {
    if (X < Y) {
      sum += C * 2 * X;
      if (C * 2 < B) {
        sum += C * (Y - X) * 2;
      } else {
        sum += B * (Y - X);
      }
    } else {
      sum += C * 2 * Y;
      if (C * 2 < A) {
        sum += C * (X - Y) * 2;
      } else {
        sum += A * (X - Y);
      }
    }
  } else {
    sum += X * A;
    sum += Y * B;
  }

  cout << sum << endl;

}