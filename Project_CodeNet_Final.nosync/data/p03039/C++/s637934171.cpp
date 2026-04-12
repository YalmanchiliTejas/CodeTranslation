#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SZ(x) ((int)(x).size())
using ll = long long;
using P = pair<int, int>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 1 << 29;
const ll INF64 = 1ll << 55;
const int mod = 1000000007;
//const int mod = 998244353;

template <class T>inline bool chmin(T &a, const T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>inline bool chmax(T &a, const T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>inline void line_out(const vector<T> vec) {
  int n = SZ(vec);
  rep(i, n) {
    cout << vec[i];
    if(i < n-1) cout << " ";
  }
  cout << endl;
  return;
}

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
  mint &operator++()
  {
    if ((x += 1) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator--()
  {
    if ((x += mod - 1) >= mod)
      x -= mod;
    return *this;
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
// h(n, r) = c(n+r-1, r)
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
  int n, m, k;
  cin >> n >> m >> k;
  combination C(n*m);
  mint ans = 0;
  for(ll d = 1ll; d <= m-1; ++d) ans += d*(m-d)*n*n;
  for(ll d = 1ll; d <= n-1; ++d) ans += d*(n-d)*m*m;
  ans *= C(n*m-2, k-2);
  cout << ans.x << endl;
}
