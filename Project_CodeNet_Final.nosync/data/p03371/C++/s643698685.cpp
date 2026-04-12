#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
  ll ans=1e9;
  rep(c,max(2*X+1,2*Y+1)){
    ll a,b;
    a = max((2*X-c+1)/2,0ll);
    b = max((2*Y-c+1)/2,0ll);
    ans = min(ans,a*A+b*B+c*C);
  }
  cout << ans << endl;
}