#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z; cin >> X >> Y >> Z;
  int ans = 0;
  X -= Z;
  while (X >= Y + Z) {
    X -= Y;
    X -= Z;
    ans++;
  }
  cout << ans << endl;
}
