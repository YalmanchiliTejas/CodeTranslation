#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
using vi=vector<int>;
#define pb push_back
int main() {
  ll n;
  cin>>n;
  int x,m;
  scanf("%d%d",&x,&m);
  map<int,int> mp;
  vi a;
  int cnt = 0;
  ll tot = 0;
  while (mp.count(x) == 0) {
    a.pb(x);
    tot += x;
    mp[x] = cnt;
    ++cnt;
    x = (ll)x*x%m;
  }
  if (n <= cnt) {
    ll ans = 0;
    rep(i,n) ans += a[i];
    cout<<ans<<endl;
    return 0;
  }
  ll c = 0;
  int s = cnt-mp[x];
  srep(i,mp[x],cnt) c += a[i];
  ll ans = tot;
  n -= cnt;
  ans += n/s*c;
  n %= s;
  int si = mp[x];
  rep(i,n) ans += a[si+i];
  cout<<ans<<endl;
  return 0;
}




















