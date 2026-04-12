#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 510000;
const int INF = 1e9;
const double pi=acos(-1);

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans=INF;
  for(ll i=0;i<=max(x,y);i++){
    ans = min(ans,i*2*c+max(x-i,0ll)*a+max(y-i,0ll)*b);
  }
  cout << ans << endl;
  return 0;
}
