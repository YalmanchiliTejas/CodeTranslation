#include <iostream>
using namespace std;

int main(void) {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;

  int AB_ONLY = X * A + Y * B;
  int MIX = 0;
  int MIX_ALL = 0;
  if (X < Y) {
    MIX = X * C + (Y - X) * B;
    MIX_ALL = Y * C;
  } else {
    MIX = Y * C + (X - Y) * A;
    MIX_ALL = X * C;
  }
  cout << min(AB_ONLY, min(MIX, MIX_ALL)) << endl;
  return 0;
}