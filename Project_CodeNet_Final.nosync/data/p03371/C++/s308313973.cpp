#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  
  if(2*C >= A+B) {
    cout << A*X+B*Y << endl;
    return 0;
  }
  
  int ans = 0;
  while(X>0 && Y>0) {
    X--;
    Y--;
    ans += 2*C;
  }
  if(2*C >= A) {
    while(X>0) {
      X--;
      ans += A;
    }
  }
  if(2*C >= B) {
    while(Y>0) {
      Y--;
      ans += B;
    }
  }
  if(X==0 && Y==0) {
    cout << ans << endl;
    return 0;
  } else {
    while(X>0) {
      X--;
      ans += 2*C;
    }
    while(Y>0) {
      Y--;
      ans += 2*C;
    }
    cout << ans << endl;
    return 0;
  }
  

}