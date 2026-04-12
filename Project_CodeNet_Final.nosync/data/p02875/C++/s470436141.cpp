#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const ll md = 998244353;
ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % md, e /= 2)
    if (e & 1) ans = ans * b % md;
  return ans;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin>>n;

  int N = n+10;
  vector<ll> inv(N,1), fac(N, 1), ifac(N, 1);
  rep(i,2,N) {
    inv[i] = md - (md / i) * inv[md % i] % md;
    fac[i] = fac[i-1] * i % md;
    ifac[i] = ifac[i-1] * inv[i] % md;
  }
  auto binom = [&](ll n, ll k) {
    if(k < 0 || k > n) return 0LL;
    return fac[n] * ifac[k] % md * ifac[n-k] % md;
  };

  ll ans = modpow(3, n);
  rep(i,0,n) {
    if(2*i <= n) continue;
    ll cur = modpow(2, n-i) * binom(n,i) % md;
    ans = (ans - 2*cur + 2*md) %md;
  }

  ans = (ans-2 + md) % md; // why?

  cout << ans << endl;
}
