#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct mint {
  ll val;
  constexpr mint(ll v = 0) noexcept : val(v % mod) {
    if (val < 0) val += mod;
  }
  constexpr mint operator + (const mint& rhs) const noexcept {
    return mint(*this) += rhs;
  }
  constexpr mint operator - (const mint& rhs) const noexcept {
    return mint(*this) -= rhs;
  }
  constexpr mint operator * (const mint& rhs) const noexcept {
    return mint(*this) *= rhs;
  }
  constexpr mint operator / (const mint& rhs) const noexcept {
    return mint(*this) /= rhs;
  }
  constexpr mint operator ~ () const noexcept {
    ll a = this->val, b = mod, u = 1, v = 0;
    while (b > 0) {
      ll t = a / b;
      a -= t * b;
      u -= t * v;
      ll c = a; a = b; b = c;
      ll w = u; u = v; v = w;
    }
    if (u < 0) u += mod;
    u %= mod;
    return u;
  }
  constexpr mint& operator += (const mint& rhs) noexcept {
    val += rhs.val;
    if (val >= mod) val -= mod;
    return *this;
  }
  constexpr mint& operator -= (const mint& rhs) noexcept {
    if (val < rhs.val) val += mod;
    val -= rhs.val;
    return *this;
  }
  constexpr mint& operator *= (const mint& rhs) noexcept {
    val = val * rhs.val % mod;
    return *this;
  }
  constexpr mint& operator /= (const mint& rhs) noexcept {
    val = val * (~(mint(rhs))).val % mod;
    return *this;
  }
  friend mint modpow (mint a, ll n) noexcept {
    auto res = mint(1);
    while(n > 0) {
      if(n&1) res *= a;
      a *= a;
      n >>= 1;
    }
    return res;
  }
  friend std::ostream& operator << (std::ostream& os, const mint& a) noexcept {
    return os << a.val;
  }
  friend std::string debug_s (mint a) noexcept {
    return std::to_string(a.val);
  }
};
namespace combinatorics {
  const int limit = 2000020;
  bool initialized = false;
  long long fac_table[limit], inv_table[limit], finv_table[limit];
  void initialize() {
    fac_table[0] = fac_table[1] = 1;
    inv_table[1] = 1;
    finv_table[0] = finv_table[1] = 1;
    for (int i = 2; i < limit; i++) {
      fac_table[i] = fac_table[i - 1] * i % mod;
      inv_table[i] = mod - inv_table[mod % i] * (mod / i) % mod;
      finv_table[i] = finv_table[i - 1] * inv_table[i] % mod;
    }
    initialized = true;
  }
  long long com(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * (finv_table[k] * finv_table[n - k] % mod) % mod;
  }
  long long perm(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * finv_table[n - k] % mod;
  }
}
using combinatorics::com;
using combinatorics::perm;


int main(){
    FIN;
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    mint sum = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }

    mint ans = 0;
    for(ll i=0;i<n;i++){
        sum -= a[i];
        ans += sum * a[i];
    }

    cout << ans << endl;
    return 0;
}
