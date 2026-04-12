#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
//using P = pair<double, double>;
using edge = struct {int to; ll cost;};

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()

const int di[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dj[] = {0, -1, 0, 1, 1, -1, 1, -1};
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;

struct prime
{
  vector<bool> num;
  prime(int n) : num(n+1, true)
  {
    num[0] = false;
    num[1] = false;
    for(int i = 2; i <= n; i++) {
      if(num[i]) {
        for(int j = 2; i*j <= n; j++) num[i*j] = false;
      }
    }
  }
  bool isPrime(int x)
  {
    return num[x];
  }
};
struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool same(int x, int y) {
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

long long gcd(long long a, long long b)
{
  if (a < b)
    swap(a, b);
  while (true)
  {
    if (a % b == 0ll)
      break;
    ll _a = a;
    a = b;
    b = _a % b;
  }
  return b;
}

long long lcm(long long a, long long b)
{
  return (max(a, b) / gcd(a, b)) * min(a, b);
}


void solve()
{
  int n, m;
  cin >> n >> m;
  if(m >= n) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

int main()
{
  solve();
  return 0;
}
