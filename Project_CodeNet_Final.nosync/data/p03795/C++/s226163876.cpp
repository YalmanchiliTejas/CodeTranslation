#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()

template <class T> inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using DoP = pair<double, double>;
using edge = struct{ int to; ll cost;};

const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 1e9 + 100;
const ll INF64 = 7e18l;
const int mod = 1000000007;

struct Sieve
{
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1)
  {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i)
    {
      if (f[i])
        continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i)
      {
        if (!f[j])
          f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorList(int x)
  {
    vector<int> res;
    while (x != 1)
    {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x)
  {
    vector<int> fl = factorList(x);
    if (fl.size() == 0)
      return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl)
    {
      if (res.back().first == p)
      {
        res.back().second++;
      }
      else
      {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};
struct UnionFind
{
  vector<int> par;
  UnionFind(int N) : par(N)
  {
    for (int i = 0; i < N; i++)
      par[i] = i;
  }
  int root(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y)
  {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }
  bool same(int x, int y)
  {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
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

  // for prime mod
  mint inv() const
  {
    return pow(mod - 2);
  }
  mint &operator/=(const mint a)
  {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};
struct combination
{
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1)
  {
    assert(n < mod);
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
  int n;
  cin >> n;
  cout << 800*n - 200*(n/15) << endl;
}
