#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;
using ll = long long;
const ll mod =  1000000007;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent, ll module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ ll root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2, mod);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

vector<vector<ll>> dp;

combination table(2 * 100000 + 50);

signed main() {
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  ll p = table.C(n*m, 2);
  ll ans = 0;
  REP(i, m) {
    ll wl = n * n % mod * inverse(2) % mod * (m-i) % mod * (m-1-i) % mod;
    ans = (ans + wl) % mod;
  }
  REP(i, n) {
    ll hl = m * m % mod * inverse(2) % mod * (n-i) % mod * (n-1-i) % mod;
    ans = (ans + hl) % mod;
  }
  cout << ans * (table.C(n*m-2, k-2)) % mod << endl;
  return 0;
}
