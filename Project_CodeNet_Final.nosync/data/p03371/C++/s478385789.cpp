#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  
  if (X >= Y) {
    if (A > 2*C) ans += 2*X*C;
    else if (A+B > 2*C) ans += 2*Y*C+(X-Y)*A;
    else ans += X*A+Y*B;
  }
  else {
    if (B > 2*C) ans += 2*Y*C;
    else if (A+B > 2*C) ans += 2*X*C+(Y-X)*B;
    else ans += X*A+Y*B;
  }
  cout << ans << endl;
}