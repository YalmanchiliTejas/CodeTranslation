#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y,ans;
  cin >> a >> b >> c >> x >> y;
  ans = max(x,y)*2*c;
  int d;
  if(x >= y) d = y*2*c+(x-y)*a;
  else d = x*2*c+(y-x)*b;
  ans = min(ans,d);
  ans = min(ans,x*a+y*b);
  cout << ans << endl;
}
