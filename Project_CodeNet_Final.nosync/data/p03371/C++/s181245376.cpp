#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
 
int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int64_t ans = 0;
  if(A + B >= C*2){
    ans += C * 2 * min(X, Y);
    if(Y >= X){
      if(B < 2 * C){
        ans += B * (Y-X);
      }
      else{
        ans += C * 2 * (Y-X);
      }
    }
    else{
      if(A < 2 * C){
        ans += A * (X-Y);
      }
      else{
        ans += C * 2 * (X-Y);
      }
    }
  }
  else{
    ans += A*X + B*Y;
  }
  cout << ans << endl;
}