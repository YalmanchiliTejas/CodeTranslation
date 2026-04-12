#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z; cin >> X >> Y >> Z;
  
  int ans = X / (Y+Z);
  if (X % (Y+Z) == 0 || X%(Y+Z) < Z) cout << ans-1 << endl;
  else cout << ans << endl;
}