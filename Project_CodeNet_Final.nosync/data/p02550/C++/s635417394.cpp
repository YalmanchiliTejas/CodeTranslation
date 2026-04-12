#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

ll f( ll a, ll m ){
  return a*a%m;
}

int main(){
  ll n,x,m;cin >> n >> x >> m;
  map<ll,ll> mp;
  vector<ll> v;
  ll a = x;
  v.push_back(a);
  mp[a]++;
  ll l,r;
  rep(i,1000000){
    a = f(a,m);
    if( mp[a] > 0 ){
      l = find(v.begin(),v.end(),a)-v.begin();
      r = i;
      break;
    }
    v.push_back(a);
    mp[a]++;
  }
  ll ans = 0;
  if( n-1 <= l-1 ){
    for(ll i=0;i<n;++i){
      ans += v.at(i);
    }
    cout << ans << endl;
    return 0;
  }
  for(ll i=0;i<l;++i) ans += v.at(i);
  n -= l;

  ll len = r-l+1;
  ll sum = 0;
  for(ll i=l;i<=r;++i) sum += v.at(i);

  ans += n/len*sum;
  if( n%len != 0 )
    for(ll i=l;i<=n%len+l-1;++i) ans += v.at(i);

  cout << ans << endl;

  return 0;
}