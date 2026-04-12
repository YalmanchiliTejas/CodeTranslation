#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int a,b,c,x,y;
  cin >>a >>b >>c >>x >>y;
  ll ans = 0;
  if(a+b>2*c){
    int z = min(x,y);
    ans += 2*z*c;
    x -= z;
    y -= z;
  }
  if(a>2*c){
    ans += 2*x*c;
    x = 0;
    y = max(0,y-x);
  }
  if(b>2*c){
    ans += 2*y*c;
    y = 0;
    x = max(0,x-y);
  }
  ans += a*x+b*y;
  cout << ans << endl;
  return 0;
}