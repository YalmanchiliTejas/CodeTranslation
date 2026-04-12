#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,x,y;
  cin >>a>>b>>c>>x>>y;
  int ans = 0;
  if(a+b>2*c){
    int t = min(x,y);
    ans += t*2*c;
    x -= t;
    y -= t;
  }
  ans += x*min(a,2*c);
  x = 0;
  ans += y*min(b,2*c);
  y = 0;
  cout << ans << endl;
}