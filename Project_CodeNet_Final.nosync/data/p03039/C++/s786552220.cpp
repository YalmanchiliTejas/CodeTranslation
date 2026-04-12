#include <iostream>
#include <vector>
#include <ctime>
#include <array>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <limits>  //std::numeric_limits<int>::max(), min()


class MyPow {
  private:
  typedef long long ll;
  std::unordered_map<ll, ll> memo;

  public:
  ll MOD = std::numeric_limits<long long>::max();

  MyPow ( ll a_ ) {
    memo[0] = 1 % MOD;
    memo[1] = a_ % MOD;
  }

  ll power ( ll p ) {
    if ( memo.count(p) != 0 ) return memo[p];
    return memo[p] = ((power(p/2)%MOD) * (power(p-p/2)%MOD)) % MOD;
  }
};

namespace MyMod {
  typedef long long ll;
  ll mod = 1000000007LL;

  ll add ( ll a, ll b) {
    return ((a%mod) + (b%mod))%mod;
  }

  ll sub ( ll a, ll b) {
    return ( a%mod + mod - b%mod)%mod;
  }

  ll mul ( ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
  }

  ll div ( ll a, ll b) {
    MyPow k(b); k.MOD = mod;
    return ((a%mod) * k.power(mod-2)) % mod;
  }
};

long long combination(long long N, long long r) {
  long long numerator = 1;
  for(long long i=N-r+1; i<=N; i++) numerator = MyMod::mul(numerator, i);

  long long denominator = 1;
  for(long long i=1; i<=r; i++ ) denominator = MyMod::mul(denominator, i);

  return MyMod::div ( numerator, denominator );
}

int main (void) {
  int N, M, K;
  std::cin >> N >> M >> K;

  // sum x
  long long sumx = 0;
  for(int i=1; i<=M-1; i++) sumx = MyMod::add(sumx, MyMod::mul(MyMod::mul(MyMod::mul(N,N),i), M-i) );

  // sum y
  long long sumy = 0;
  for(int i=1; i<=N-1; i++) sumy = MyMod::add(sumy, MyMod::mul(MyMod::mul(MyMod::mul(M,M),i), N-i) );

  // comb
  long long comb = combination(N*M-2, K-2);

  // ans
  long long ans = MyMod::mul(comb, MyMod::add(sumx,sumy));
  std::cout << ans << std::endl;

  return 0;
}