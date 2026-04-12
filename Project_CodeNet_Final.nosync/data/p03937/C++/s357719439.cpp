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

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];
  int sum = 0;
  rep(i, h) rep(j, w) if(a[i][j] == '#') ++sum;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  queue<P> q;
  auto update = [&](P now) {
    int i = now.first, j = now.second;
    rep(k, 2) {
      int ni = i+di[k], nj = j+dj[k];
      if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if(dist[ni][nj] == INF) {
        dist[ni][nj] = dist[i][j] + 1;
        q.push(P(ni, nj));
      }
    }
  };

  dist[0][0] = 1;
  q.push(P(0, 0));

  while(!q.empty()) {
    P now = q.front(); q.pop();
    update(now);
  }

  if(dist[h-1][w-1] == sum) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}