#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

signed main(){
  ll n;cin>>n;
  vector<ll> v(n),t(0);//見たならtrue
  rep(i,n)cin>>v[i];

  t.pb(v[0]);
  for(int i=1;i < n;i++)
  {
    int itr=lower_bound(all(t),v[i])-t.begin();

    if(!itr)t.insert(t.begin(),v[i]);
    else t[itr-1]=v[i];

  }
  cout<<siz(t)<<endl;
}