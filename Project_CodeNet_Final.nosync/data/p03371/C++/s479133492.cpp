#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans;
  if(a+b>=c*2){
    if(x>=y){
      ans = min(c*x*2,c*y*2+a*(x-y));
    }
    else ans = min(c*y*2,c*x*2+b*(y-x));                                                                         
  }
  else ans = a*x + b*y;
  cout << ans << endl;
}