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
const ll INF64 = 1ll << 62;
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

vector<ll> num(51), p(51);
void level(int n) {
  if(n == 0) {
    num[n] = 1;
    p[n] = 1;
  }
  else {
    num[n] = 2*num[n-1]+3;
    p[n] = 2*p[n-1]+1;
  }
}

ll check(int level, ll x) {
  if(level == 0) return 1;
  if(x == num[level]) return p[level];
  if(x > num[level-1]+2) return p[level-1]+1+check(level-1, x-num[level-1]-2);
  if(x == num[level-1]+2) return p[level-1]+1;
  if(x > 1) return check(level-1, x-1);
  else return 0;
}

int main()
{
  int n;
  ll x;
  cin >> n >> x;
  rep(i, 51) level(i);

  cout << check(n, x) << endl;
}
