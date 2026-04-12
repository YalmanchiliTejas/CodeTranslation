#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int n;
  cin>>n;
  vector<ll> a(n);
  for(auto& ai:a)cin>>ai;
  vector<ll> sum(n+1);
  rep(i,n)sum[i+1]=sum[i]+a[i];
  ll ans = 0;
  constexpr ll MOD = 1e9+7;
  rep(i,n-1){
    ll tmp = sum[n]-sum[i+1];
    tmp %= MOD;
    ans += a[i]*tmp%MOD;
    ans %= MOD;
  }
  cout<<(ans)<<endl;

}