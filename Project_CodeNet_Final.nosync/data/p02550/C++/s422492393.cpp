#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)

main(void) {
  ll n,x,m;cin>>n>>x>>m;
  vector<ll> id(m,-1);
  vector<ll> a;
  ll len=0;
  ll tot=0;
  while(id[x]==-1){
    a.push_back(x);
    id[x]=len;
    tot+=x;
    len++;
    x=(x*x)%m;
  }
  ll s=0;
  ll c=len-id[x];
  for(ll i=id[x];i<=len;i++) s+=a[i];
  ll ans=0;
  if(n<=len){
    rep(i,n) ans+=a[i];
  } else {
    ans+=tot;
    n-=len;
    ans+=s*(n/c);
    n%=c;
    rep(i,n) ans+=a[id[x]+i];
  }
  cout << ans << endl;
  return 0;
}