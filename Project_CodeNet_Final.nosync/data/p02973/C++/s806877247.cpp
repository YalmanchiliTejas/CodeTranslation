#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
  ll n;cin>>n;
  vector<ll> t(0);//見たならtrue
  rep(i,n)
  {
    ll a;cin>>a;
    if(!i){t.pb(a);continue;}

    int itr=lower_bound(all(t),a)-t.begin();

    if(!itr)t.insert(t.begin(),a);
    else t[itr-1]=a;

  }
  cout<<siz(t)<<endl;
}