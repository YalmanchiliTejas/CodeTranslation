#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;

  //c*2*max(x,y)
  //c*2*min(x,y)+(a or b)*((x-min(x,y)) or (y-min(x,y)))
  //2a+2b

  // 2c min(x,y)>2a+2b?
  
  ll ans;
  if(2*c*min(x,y)+(x-min(x,y))*a+(y-min(x,y))*b>x*a+y*b){
    ans = x*a+y*b;
  }
  else{
    ans = 2*c*min(x,y)+(x-min(x,y))*a+(y-min(x,y))*b;
  }
  ans = min(ans,2*c*max(x,y));
  
  cout << ans << endl;
  
  return 0;
}
