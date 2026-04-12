#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans = pow(10,9);
  if(X>=Y){
    rep(i,2*X+1){
      if(i<2*Y) ans = min(ans, A*(X-i/2)+B*(Y-i/2)+C*i);
      else ans = min(ans, A*(X-i/2)+C*i);
    }
  }
  else{//X<Y
    rep(i,2*Y+1){
      if(i<2*X) ans = min(ans, A*(X-i/2)+B*(Y-i/2)+C*i);
      else ans = min(ans, B*(Y-i/2)+C*i);
    }
  }
  cout<<ans<<endl;
  return 0;
}
