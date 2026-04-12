#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
const int maxn = 1e7 + 10;
ll n;
 
ll fac[maxn];
ll inv[maxn];
ll ci[maxn];
 
ll quickpow(ll a, ll b){
  ll ans = 1 % mod;
  while(b){
    if(b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
 
 
void init(){
 
  fac[0] = ci[0] = 1;
  for(ll i = 1; i <= n; i ++){
    fac[i] = 1ll * fac[i - 1] * i % mod;
    ci[i] = ci[i - 1] * 2 % mod;
  }
  inv[n] = quickpow(fac[n], mod - 2);
  for(ll i = n - 1; i >= 0; i --)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
 
 
}
 
 
ll C(ll x, ll y){
  return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
 
 
int main()
{
  scanf("%lld",&n);
  init();
  ll ans = quickpow(3ll ,n) % mod;
  ll x = 0;
  for(ll i = n / 2 + 1; i <= n; i ++)
    x += C(n, i) * ci[n - i] % mod;
  printf("%lld\n",(ans - x * 2 % mod + mod) % mod);
  return 0;
}