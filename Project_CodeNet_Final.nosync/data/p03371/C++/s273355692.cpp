#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int dc = 2*c;
  ll ans = 0;
  if(dc <= a + b){
    if(x < y){
      ans += dc*x;
      y -= x;
      if(dc <= b) ans += dc*y;
      else ans += b*y;
    }else{
      ans += dc * y;
      x -= y;
      if(dc <= a) ans += dc * x;
      else ans += a * x;
    }
  }else{
    ans = x*a + b*y;
  }
  cout << ans << endl;
  return 0;
}