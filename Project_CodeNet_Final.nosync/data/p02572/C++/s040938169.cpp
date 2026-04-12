#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1000000007;

// ref: https://github.com/atcoder-live/library/blob/master/mint.cpp
struct mint
{
  ll x;
  mint(ll x = 0) : x((x % MOD + MOD) % MOD)
  {
  }
  mint operator-() const
  {
    return mint(-x);
  }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const
  {
    return mint(*this) += a;
  }
  mint operator-(const mint a) const
  {
    return mint(*this) -= a;
  }
  mint operator*(const mint a) const
  {
    return mint(*this) *= a;
  }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const
  {
    return pow(MOD - 2);
  }
  mint &operator/=(const mint a)
  {
    return *this *= a.inv();
  }
  mint operator/(const mint a) const
  {
    return mint(*this) /= a;
  }
};
istream &operator>>(istream &is, const mint &a)
{
  return is >> a.x;
}
ostream &operator<<(ostream &os, const mint &a)
{
  return os << a.x;
}

struct combination
{
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1)
  {
    assert(n < MOD);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i)
      ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k)
  {
    if (k < 0 || k > n)
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  vector<mint> arr(N + 1);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
    arr[i + 1] = arr[i] + A[i];
  }
  mint ans = 0;
  for (int i = 0; i < N; ++i)
  {
    ans += mint(A[i]) * (arr[N] - arr[i + 1]);
  }
  cout << ans << endl;

  return 0;
}
