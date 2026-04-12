#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;

constexpr ll MOD = 1e9+7;

signed main(){

  int n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;++i)
    cin>>a[i];

  ll sum = 0;
  for(int i=0;i<n;++i)
    sum += a[i];
  // a[0],a[1],a[2],a[3],...,a[n-1]の和
  sum %= MOD;

  ll ans = 0;
  for(int i=0;i<n-1;++i){
    sum -= a[i];
    if(sum<0)sum+=MOD;
    ll add = a[i]*sum%MOD;
    ans += add;
    ans %= MOD;
  }
  cout<<(ans)<<endl;

}
