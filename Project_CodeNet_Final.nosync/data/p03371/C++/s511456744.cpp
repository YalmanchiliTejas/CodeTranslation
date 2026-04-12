#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int cost = 0;
  if (A > 2 * C) {
    cost = 2 * X * C;
    Y -= X;
    X = 0;
  }
  if (B > 2 * C && Y > 0) {
    cost += 2 * Y * C;
    X -= Y;
    Y = 0;
  }

  if (A + B > 2 * C) {
    int mn = std::max(std::min(X, Y), 0);
    cost += 2 * mn * C;
    X -= mn;
    Y -= mn;
  }

  if (X > 0) {
    cost += X * A;
  }
  if (Y > 0) {
    cost += Y * B;
  }

  cout << cost << endl;

  return 0;
}
