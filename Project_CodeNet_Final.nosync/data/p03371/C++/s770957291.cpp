#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int dc = c*2;
  int x, y;
  cin >> x >> y;
  int ans;
  if(dc <= a + b){
    int m = min(x, y);
    ans = m*dc;
    x -= m;
    y -= m;
    // cerr << x << " " << y << " " << a << " " << b << " " << dc << endl;
    if(y > 0){
      if(dc <= b){
        ans += dc*y;
      }else{
        ans += b*y;
      }
    }else{
      if(dc <= a){
        ans += dc*x;
      }else{
        ans += a*x;
      }
    }
  }else{
    ans = x*a + y*b;
  }
  cout << ans << endl;
  return 0;
}