#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
  ll MOD = 1e9+7;

ll modpow(ll a, ll n){
  if(n==1) return a%MOD;
  if(n%2==1) return (a*modpow(a,n-1))%MOD;
  else{
    ll t=modpow(a,n/2)%MOD;
    return (t*t)%MOD;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll N; cin>>N;
  vector<ll> A(N,0);
  rep(i,N) cin>>A[i];
  ll sum=0;
  rep(i,N) (sum+=A[i])%=MOD;
  ll g = modpow(2,MOD-2);
  ll ans = 0;
  rep(i,N){
    ans += ((sum-A[i]) * A[i])%MOD;
    ans = (ans+MOD)%MOD;
  }
  ans *= g;
  ans %= MOD;
  cout<<ans<<endl;
}
