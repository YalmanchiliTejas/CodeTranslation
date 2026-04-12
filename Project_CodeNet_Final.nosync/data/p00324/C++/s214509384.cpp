#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll d[n+1],ans=0;
  d[0]=0;
  map<ll,ll> m;
  m[0]=0;
  for(ll i=1,x; i<=n; i++) {
    cin >> x;
    d[i]=x+d[i-1];
    if(m.count(d[i])) ans=max(ans,i-m[d[i]]);
    else m[d[i]]=i;
  }
  cout << ans << endl;
  return 0;
}
