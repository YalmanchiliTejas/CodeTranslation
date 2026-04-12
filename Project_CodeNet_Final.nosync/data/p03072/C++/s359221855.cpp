#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vp;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF=99999999999999;
const ll MOD=1000000007;
 
int main() {
  ll n;
  cin >> n;
  vl h;
  inputv(h,n);
  ll mx = 0;
  ll ans = 0;
  rep(i,n){
    if(h[i] >= mx){
      ans++;
    }
    mx = max(mx,h[i]);
  }
  cout << ans;
 return 0;
}
