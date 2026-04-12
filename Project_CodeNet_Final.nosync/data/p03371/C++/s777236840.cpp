#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;

int main() {
  ll A,B,C,X,Y;
  cin >> A>>B>>C>>X>>Y;
  
  ll ans;
  if (A+B<=2*C) {
    ans=A*X+B*Y;
  }
  else {
    if (X>=Y) {
      if (A>2*C) {
        ans = 2*X*C;
      }
      else {
        ans = 2*C*Y+A*(X-Y);
      }
    }
    else {
      if (B>2*C) {
        ans = 2*Y*C;
      }
      else {
        ans = 2*C*X+B*(Y-X);
      }
    }
  }
  cout << ans;
}