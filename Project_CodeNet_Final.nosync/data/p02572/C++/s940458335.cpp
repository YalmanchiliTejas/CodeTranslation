#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

ll mpow(ll x, ll n) {
  ll res=1;
  while(n>0) {
    if(n&1) {
      res=res*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll sum=0;
  for(ll i=0;i<n;i++) (sum+=a[i])%=mod;
  (sum*=sum)%=mod;
  for(ll i=0;i<n;i++) {
    sum=(sum-a[i]*a[i]%mod+mod)%mod;
  }
  sum=sum*mpow(2,mod-2)%mod;
  cout << sum << endl;
}