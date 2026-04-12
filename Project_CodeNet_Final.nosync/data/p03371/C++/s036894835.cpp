#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a,b,c,x,y; cin >>a >>b >>c >>x >>y;
  /* a+b>2cの場合、xとyの差が偶数ならcを出来るだけ買う。
    で、残りの例えばxが4枚とかになったとき、aを4枚買うかcを8枚
    買うかで場合分け
  */
  int ans;
  if (a+b<=2*c) ans = a*x + b*y;
  else{
    if (x==y) ans = c * 2*x;
    else if (x>y){
      if (a>2*c) ans = c * 2*x;
      else       ans = c * 2*y + a*(x-y);
    }else if (x<y){
      if (b>2*c) ans = c * 2*y;
      else       ans = c * 2*x + b*(y-x);
    }
  }
  cout <<ans;
  cout <<endl;
}
