#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

//階乗,factで初期化
vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

//nCk 繰り返し高速
ll comb(ll n, ll k) {
  return tfact.at(n)*mpow(tfact.at(k),mod-2)%mod*mpow(tfact.at(n-k),mod-2)%mod;
}

int main() {
  ll n,m,k;
  cin >> n >> m >> k;
  ll ans=0;
  fact(n*m);
  for(ll i=1;i<=n-1;i++) {
    ll tans=m*m%mod*(n-i)%mod*i%mod*comb(n*m-2,k-2)%mod;
    (ans+=tans)%=mod;
  }
  for(ll i=1;i<=m-1;i++) {
    ll tans=n*n%mod*(m-i)%mod*i%mod*comb(n*m-2,k-2)%mod;
    (ans+=tans)%=mod;
  }
  cout << ans << endl;
}