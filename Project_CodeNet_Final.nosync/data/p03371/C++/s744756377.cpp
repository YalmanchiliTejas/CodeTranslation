#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,C,X,Y,ans;
  cin >> A >> B >> C >> X >> Y;
  int mi = min(X,Y);
  if(A+B > 2*C){
    X -= mi;
    Y -= mi;
    ans = mi * 2 * C;
    if(X)ans = min(ans + X*A,ans + 2*C*X);
    if(Y)ans = min(ans + Y*B,ans + 2*C*Y);
  }
  else ans = A * X + B * Y;
  cout << ans << endl;
}
