#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;++i) cin >> a[i];
  const ll mod=1000000007;
  ll ans=0;
  ll x=0;
  for(int i=0;i<n;++i){
    ans=(ans+a[i]*x)%mod;
    x=(x+a[i])%mod;
  }
  cout << ans << endl;
  return 0;
}
