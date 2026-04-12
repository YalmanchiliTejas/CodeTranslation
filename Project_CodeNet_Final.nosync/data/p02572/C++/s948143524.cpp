#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for (int i = 0; i < (a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template <typename Head> void dump(Head &&head) {
  cerr << head;
  dump();
}
template <typename Head, typename... Tail>
void dump(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  dump(forward<Tail>(tail)...);
}
#define debug(...)                                                             \
  do {                                                                         \
    cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = ";                        \
    dump(__VA_ARGS__);                                                         \
  } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template <typename T> struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL << 60;
const ll mod = 1000000007;

struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
  bool operator==(const mint a) const { return x == a.x; }
  bool operator!=(const mint a) const { return x != a.x; }
  friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};

int main() {
  ll n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  mint ans = 0;
  mint sum = 0;
  rep(i, n) sum += a[i];

  rep(i, n) {
    sum -= a[i];
    ans += sum * a[i];
  }

  cout << ans << endl;

  return 0;
}
