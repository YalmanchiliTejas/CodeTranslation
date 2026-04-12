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
  int dc = c * 2;
  int ans = 0;
  if(dc <= a + b){
    if(x < y){
      ans += dc * x;
      if(dc <= b) ans += dc *(y-x);
      else ans += b *(y-x);
    }else{
      ans += dc * y;
      if(dc <= a) ans += dc * (x-y);
      else ans += a * (x - y);
    }
  }else{
    ans += x * a;
    ans += y * b;
  }
  cout << ans << endl;
  return 0;
}