#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans = INT64_MAX;
  for (int i = 0; i <= x || i <= y; i++)
  {
    if (x - i >= 0 && y - i >= 0)
    ans = min(ans, (ll) a * (x - i) + b * (y - i) + (i * 2 * c));
    else if (x - i < 0 && y - i >= 0)
    ans = min(ans, (ll) b * (y - i) + (i * 2 * c));
    else if (x - i >= 0 && y - i < 0)
    ans = min(ans, (ll) a * (x - i) + (i * 2 * c));
    else 
    ans = min(ans, (ll)(i * 2 * c));
  }
  cout << ans << endl;
  
}