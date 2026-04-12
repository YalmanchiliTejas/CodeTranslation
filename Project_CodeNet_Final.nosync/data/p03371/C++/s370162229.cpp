#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;cin >> a >> b >> c >> x >> y;
  int ans = 0;
  ans += min(a+b,2*c)*min(x,y);
  if(x > y)ans += min(a,2*c) * (x-y);
  else ans += min(b,2*c)*(y-x);
  cout << ans << endl;
  return 0;
}