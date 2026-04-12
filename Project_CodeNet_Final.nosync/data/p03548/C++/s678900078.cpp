#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  X -= Z * 2;
  X -= Y;
  int cnt = 1 + X / (Y+Z);
  cout << cnt << endl;

  return 0;
}
