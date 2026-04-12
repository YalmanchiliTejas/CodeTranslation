#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1e9;
  ans = min(a*x+b*y, ans);
  ans = min(max(x,y)*2*c, ans);
  if(x > y)
    ans = min(2*c*y+(x-y)*a, ans);
  else
    ans = min(2*c*x+(y-x)*b, ans);
  cout << ans << endl;
  return 0;
}