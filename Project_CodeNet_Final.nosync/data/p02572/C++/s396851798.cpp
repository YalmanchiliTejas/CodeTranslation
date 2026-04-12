#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ll mod=1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> s(n+1);
  rep(i,n) cin >> a[i];
  s[0] = 0;
  rep(i,n){
    s[i+1] = (s[i] + a[i]);
  }
  
  ll ans=0;
  rep(i,n-1){
    ans += a[i] * ((s[n] - s[i+1])%mod);
    ans = ans % mod;
  }
  cout << ans << endl;
  
  return(0);
}