#include <bits/stdc++.h>
#define inf (long long)(1e18)
using namespace std;

template <int mod = (int)(1e9 + 7)>
struct ModInt {
  int x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(int64_t y)
      : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  constexpr ModInt &operator+=(const ModInt &p) noexcept {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &p) noexcept {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &p) noexcept {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &p) noexcept {
    *this *= p.inverse();
    return *this;
  }
  constexpr ModInt operator-() const { return ModInt(-x); }
  constexpr ModInt operator+(const ModInt &p) const noexcept {
    return ModInt(*this) += p;
  }
  constexpr ModInt operator-(const ModInt &p) const noexcept {
    return ModInt(*this) -= p;
  }
  constexpr ModInt operator*(const ModInt &p) const noexcept {
    return ModInt(*this) *= p;
  }
  constexpr ModInt operator/(const ModInt &p) const noexcept {
    return ModInt(*this) /= p;
  }
  constexpr bool operator==(const ModInt &p) const noexcept { return x == p.x; }
  constexpr bool operator!=(const ModInt &p) const noexcept { return x != p.x; }
  constexpr ModInt inverse() const noexcept {
    int a = x, b = mod, u = 1, v = 0, t = 0;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  constexpr ModInt pow(int64_t n) const {
    ModInt res(1), mul(x);
    while (n) {
      if (n & 1) res *= mul;
      mul *= mul;
      n >>= 1;
    }
    return res;
  }
  friend constexpr ostream &operator<<(ostream &os, const ModInt &p) noexcept {
    return os << p.x;
  }
  friend constexpr istream &operator>>(istream &is, ModInt &a) noexcept {
    int64_t t = 0;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  constexpr int get_mod() { return mod; }
};

struct dat {
  int to;
  long long t;
  bool operator<(const dat &r) const { return t > r.t; }
};

int n, m, s, t;
vector<vector<dat>> g;
vector<long long> dist[2];
vector<ModInt<>> cnt[2];

ModInt<> solve();
void dijk(int root, vector<long long> &d, vector<ModInt<>> &c);

int main() {
  cin >> n >> m >> s >> t;
  --s, --t;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    g[--x].push_back({--y, c});
    g[y].push_back({x, c});
  }
  cout << solve() << endl;
  return 0;
}

ModInt<> solve() {
  dijk(s, dist[0], cnt[0]);
  dijk(t, dist[1], cnt[1]);
  long long cost = dist[0][t];
  ModInt<> res = cnt[0][t] * cnt[1][s];
  for (int i = 0; i < n; ++i)
    if (dist[0][i] + dist[1][i] == cost) {
      if (dist[0][i] == dist[1][i])
        res -= (cnt[0][i] * cnt[1][i]).pow(2);
      else
        for (auto [to, c] : g[i])
          if (dist[0][i] * 2LL < cost && cost < dist[0][to] * 2LL) {
            if (dist[0][i] + dist[1][to] + c != cost) continue;
            res -= (cnt[0][i] * cnt[1][to]).pow(2);
          }
    }
  return res;
}

void dijk(int root, vector<long long> &d, vector<ModInt<>> &c) {
  priority_queue<dat> pq;
  d.assign(n, inf);
  d[root] = 0;
  c.assign(n, 0);
  c[root] = 1;
  pq.push({root, 0});
  while (pq.size()) {
    auto [now, time] = pq.top();
    pq.pop();
    if (time != d[now]) continue;
    for (auto [to, cos] : g[now]) {
      dat nxt = {to, time + cos};
      if (d[to] > nxt.t) {
        pq.push(nxt);
        d[to] = nxt.t;
        c[to] = c[now];
      } else if (d[to] == nxt.t)
        c[to] += c[now];
    }
  }
}