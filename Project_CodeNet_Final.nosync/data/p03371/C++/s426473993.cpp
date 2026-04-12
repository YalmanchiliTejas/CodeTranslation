#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 0;
  if(a+b > 2*c){
    ans += 2*c*min(x,y);
  }
  else{
    ans += (a+b)*min(x,y);
  }
  if(x > y){
    if(a > 2*c) ans += 2*c*(max(x,y)-min(x,y));
    else ans += a*(max(x,y)-min(x,y));
  }
  else{
    if(b > 2*c) ans += 2*c*(max(x,y)-min(x,y));
    else ans += b*(max(x,y)-min(x,y));
  }
  cout << ans << endl;
}
