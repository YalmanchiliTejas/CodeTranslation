#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SZ(x) ((int)(x).size())
using ll = long long;
using P = pair<ll, ll>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 1 << 29;
const ll INF64 = 1ll << 45;
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
  string s;
  int d;
  cin >> s >> d;
  int n = s.size();
  mint dp[n+1][2][d];
  rep(i, n+1) rep(j, 2) rep(k, d) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i, n) {
    int x = s[i]-'0';
    rep(j, 2) {
      rep(k, d) {
        rep(t, (j?10:x+1)) dp[i+1][j || t < x][(k+t)%d] += dp[i][j][k];
      }
    }
  }
  mint ans = dp[n][0][0]+dp[n][1][0];
  --ans;
  cout << ans.x << endl;
}