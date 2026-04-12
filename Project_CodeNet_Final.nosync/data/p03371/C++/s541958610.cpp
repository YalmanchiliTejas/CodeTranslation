#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int total = 0;
  if (A + B > 2 * C) {
    int n = min(X, Y);
    total += n * 2 * C;
    X -= n;
    Y -= n;
  }

  if (A > 2 * C) {
    total += 2 * C * X;
  } else {
    total += A * X;
  }

  if (B > 2 * C) {
    total += 2 * C * Y;
  } else {
    total += B * Y;
  }

  cout << total << endl;

  return 0;
}