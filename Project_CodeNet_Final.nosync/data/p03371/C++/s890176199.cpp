#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;


int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a+b>2*c){
    ans += 2*c*min(x,y);
    if(x-y>=0){
      if(a>2*c) ans += (x-y)*2*c;
      else      ans += (x-y)*a;
    }
    else{
      if(b>2*c) ans += (y-x)*2*c;
      else      ans += (y-x)*b;
    }
  }
  else ans += x*a+y*b;
  cout << ans << endl;

  return 0;
}
