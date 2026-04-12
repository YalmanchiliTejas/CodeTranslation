#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

using ll = long long; 
using P = pair<int,int>;

int main() {

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;
  int num, rem;
  if (A+B > C*2) {
    num = min(X, Y);
    ans += num * C * 2;
    if (X > Y){
      rem = X - Y;
      if (A < 2*C){
        ans += A * rem;
      }
      else { 
        ans += C * rem *2;
      }
    } 
    else { 
      rem = Y - X;
      if (B <2*C){
        ans += B * rem;
      }
      else {
        ans += C * rem * 2;
      }
    }
  } 
  else {
    ans += A * X + B * Y;
  }
  
  cout << ans << endl;
  return 0;
}

