#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

signed main(){
  ll n;cin>>n;
  multiset<ll,greater<ll>> t;//見たならtrue
  rep(i,n)
  {
    ll a;cin>>a;
    auto itr=t.upper_bound(a);
    if(t.end()!=itr)t.erase(itr);
    t.insert(a);
  }
  cout<<siz(t)<<endl;
}