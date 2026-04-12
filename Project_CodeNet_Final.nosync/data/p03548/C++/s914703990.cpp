#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ans = 0;
  if (X % (Y + Z) >= Z) ans = X / (Y + Z);
  else ans = X / (Y + Z) - 1;
  cout << ans << endl;
}