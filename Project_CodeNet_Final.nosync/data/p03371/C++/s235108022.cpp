#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
static const int inf = 1 << 30;

int main(void) {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int argmin = -1;
  int minimum = A * X + B * Y;
  int preminimum = inf;
  for (int i = 0; i <= 2 * X; i++) {
    minimum = min(minimum, A * (X - i / 2) + C * i);
    if (preminimum > minimum) {
      argmin = i;
    }
  }
  int aa = A * (X - argmin / 2) + B * max(0, Y - argmin / 2) + C * argmin;
  minimum = inf;
  preminimum = inf;
  for (int i = 0; i <= 2 * Y; i++) {
    minimum = min(minimum, B * (Y - i / 2) + C * i);
    if (preminimum > minimum) {
      argmin = i;
    }
  }
  int bb = B * (Y - argmin / 2) + A * max(0, X - argmin / 2) + C * argmin;
  int mm = min(aa, bb);
  mm = min(mm, A * X + B * Y);
  cout << mm << endl;
}