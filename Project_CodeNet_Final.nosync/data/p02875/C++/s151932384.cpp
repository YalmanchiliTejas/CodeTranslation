#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

constexpr ll MOD = 998244353;

// a^-1 mod p
ll inv(ll a,ll p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

int main()
{
  ll n;
  cin>>n;
  vecll fact(n+1, 0);
  fact[0] = 1;
  for (ll i:irange(0l, n)) {
    fact[i+1] = fact[i] * (i+1) % MOD;
  }
  vecll finv(n+1, 0);
  finv.back() = inv(fact.back(), MOD);
  for (ll i=n-1; i>=0; --i) {
    finv[i] = finv[i+1] * (i+1) % MOD;
  }
  vecll pow2(n+1, 0);
  pow2[0] = 1;
  for (ll i:irange(0l, n)) {
    pow2[i+1] = 2 * pow2[i] % MOD;
  }
  ll sub = 0;
  ll half = n/2;
  for (ll i:irange(half+1, n+1)) {
    ll comb = fact[n] * finv[i] % MOD * finv[n-i] % MOD;
    sub += comb * pow2[n-i] % MOD;
    sub %= MOD;
  }
  sub *= 2;
  sub %= MOD;
  ll pow3 = 1;
  for (ll i:irange(0l, n)) {
    pow3 *= 3;
    pow3 %= MOD;
  }
  ll ans = pow3 + (MOD - sub);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
