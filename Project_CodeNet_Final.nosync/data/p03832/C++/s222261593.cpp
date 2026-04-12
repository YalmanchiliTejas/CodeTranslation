#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

constexpr ll MOD = 1000000007;

// a^-1 mod p
ll inv(ll a,ll p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

constexpr ll flen = 2000;
ll fact[flen+1];
ll ifact[flen+1];

ll comb(ll n, ll k) {
  return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main() {
  fact[0] = 1;
  REP(i,flen) {
    fact[i+1] = fact[i] * (i+1) % MOD;
  }
  ifact[flen] = inv(fact[flen], MOD);
  REP(ri,flen) {
    int i = flen - ri;
    ifact[i-1] = ifact[i] * i % MOD;
  }
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  vector<vecll> pif(flen, vecll(flen));
  REP(i,flen) {
    pif[i][0] = 1;
    REP(j,flen-1) {
      pif[i][j+1] = pif[i][j] * ifact[i] % MOD;
    }
  }
  vecll dp(n+1, 0);
  dp[0] = 1;
  FOR(i,a,b+1) {
    vecll tmp = dp;
    FOR(j,c,d+1) {
      int num = i*j;
      if (num > n) break;
      FOR(k,num,n+1) {
        ll val = dp[k-num] * comb(n-k+num, num) % MOD * fact[num] % MOD;
        val *= pif[i][j] * ifact[j] % MOD;
        val %= MOD;
        tmp[k] += val;
        tmp[k] %= MOD;
      }
    }
    swap(dp, tmp);
  }
  cout<<dp[n]<<endl;
  return 0;
}
