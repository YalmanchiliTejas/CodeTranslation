#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll A,B,C,X,Y ;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  
  if(C*2 <= A+B){
    ans += C*min(X,Y)*2;
    if(X>=Y){
      if(2*C<=A){
        ans += C*(X-min(X,Y))*2;
      }
      else if(2*C>A){
        ans += A*(X-min(X,Y));
      }
    }
    else if(X <Y){
      if(2*C<=B){
        ans += C*(Y-min(X,Y))*2;
      }
      else if(2*C>B){
        ans += B*(Y-min(X,Y));
      }
    }
  }
  else ans = A*X + B*Y;
  cout << ans << endl;
                         
}