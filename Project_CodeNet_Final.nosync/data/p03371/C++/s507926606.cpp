#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans;
  if(x>=y){
    ans=2*c*x;
    ans=min(ans, 2*c*y+(x-y)*a);
    ans=min(ans, a*x+b*y);
  }else{
    ans=2*c*y;
    ans=min(ans, 2*c*x+(y-x)*b);
    ans=min(ans, a*x+b*y);
  }
  cout << ans << endl;
  return 0;
}