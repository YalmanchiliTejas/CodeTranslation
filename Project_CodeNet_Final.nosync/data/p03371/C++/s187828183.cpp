#include <bits/stdc++.h>
using namespace std;

int main(){
  
int A, B, C, X, Y, ans;
  cin >> A >> B >> C >> X >> Y;
  
  if(X > Y){
    if(A + B < C * 2) ans = A * X + B * Y;
    else ans = min(C * 2 * X, C * 2 * Y + A * (X - Y));
  }
  
  else{
    if(A + B < C * 2) ans = A * X + B * Y;
    else ans = min(C * 2 * Y, C * 2 * X + B * (Y - X));  
  }
    
  cout << ans << endl;
  return 0;
  
}