#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 1e9+7;


ll Pow(ll x, ll n){
  if(n == 0) return 1;
  if(n % 2 == 0) return Pow(x*x % mod, n/2);
  else return x * Pow(x,n-1) % mod;
}

ll mod_inverse(ll a) {
  return Pow(a,mod-2);
}

int main(){
  ll n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum = (sum + a[i]) % mod;
  }
  ll ans = 0;
  rep(i,n) {
    ll c = (sum - a[i]) % mod;
    ans = (ans + c * a[i]) % mod;
  }
  (ans *= mod_inverse(2)) %= mod;
  if(ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
