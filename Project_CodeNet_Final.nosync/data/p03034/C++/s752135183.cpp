

#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;




int main() {
  ll n;
  cin >> n;
  vector<ll>v(n);
  rep(i,n)cin>>v[i];
  ll ans=-INF;
  for(ll c=1;c<n;c++){
    ll l=0;ll r=n-1;
    ll now=0;
    if((n-1)%c==0){
      while(l<r){
        now+=v[l]+v[r];
        ans=max(ans,now);
        l+=c;
        r-=c;
      }
    }
    else{
      now=0;
      while(r>c){
        now+=v[l]+v[r];
        ans=max(ans,now);
        l+=c;
        r-=c;
      }

    }

  }
  cout<<ans;
}
