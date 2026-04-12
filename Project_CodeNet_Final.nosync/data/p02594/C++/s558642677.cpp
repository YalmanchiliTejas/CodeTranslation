#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#include <limits>
using namespace std;
// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n)
{
vector<pair<long long, long long> > res;
for (long long p = 2; p * p <= n; ++p)
{
if (n % p != 0)
continue;
int num = 0;
while (n % p == 0)
{
++num;
n /= p;
}
res.push_back(make_pair(p, num));
}
if (n != 1)
res.push_back(make_pair(n, 1));
return res;
}
//modint
template <int MOD>
struct Fp
{
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD)
  {
    if (val < 0)
      val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator-() const noexcept
  {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp &operator+=(const Fp &r) noexcept
  {
    val += r.val;
    if (val >= MOD)
      val -= MOD;
    return *this;
  }
  constexpr Fp &operator-=(const Fp &r) noexcept
  {
    val -= r.val;
    if (val < 0)
      val += MOD;
    return *this;
  }
  constexpr Fp &operator/=(const Fp &r) noexcept
  {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b)
    {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0)
      val += MOD;
    return *this;
  }
  constexpr bool operator==(const Fp &r) const noexcept
  {
    return this->val == r.val;
  }
  constexpr bool operator!=(const Fp &r) const noexcept
  {
    return this->val != r.val;
  }
  friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
  {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
  {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};
// 二項係数ライブラリ
template <class T>
struct BiCoef
{
  vector<T> fact_, inv_, finv_;
  constexpr BiCoef() {}
  constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
  {
    init(n);
  }
  constexpr void init(int n) noexcept
  {
    fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
    int MOD = fact_[0].getmod();
    for (int i = 2; i < n; i++)
    {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = -inv_[MOD % i] * (MOD / i);
      finv_[i] = finv_[i - 1] * inv_[i];
    }
  }
  constexpr T com(int n, int k) const noexcept
  {
    if (n < k || n < 0 || k < 0)
      return 0;
    return fact_[n] * finv_[k] * finv_[n - k];
  }
  constexpr T fact(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return fact_[n];
  }
  constexpr T inv(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return inv_[n];
  }
  constexpr T finv(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return finv_[n];
  }
};
// 因数分解
long long gcd(long long x, long long y)
{
  if (y == 0)
  {
    return x;
  }
  else
  {
    return gcd(y, x % y);
  }
}
const int MOD = 1000000007;
using mint = Fp<MOD>;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
  int x;
  cin >> x;
  if(x>=30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}