#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = A*X + B*Y;
  if(A+B>2*C){
    ans-= min(X, Y)*(A+B-2*C);
  }
  
  ans=min(ans, (max(X, Y)*2*C));
  cout << ans << endl;
}