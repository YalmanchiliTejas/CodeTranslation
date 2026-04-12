#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())

using LL = long long;
template<class T, size_t D>
struct vec : vector<vec<T, D - 1>> {
  template<class... Args>
  vec(size_t n = 0, Args... args)
    : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template<class T>
struct vec<T, 1> : vector<T> {
  template<class... Args>
  vec(Args... args)
    : vector<T>(args...) {}
};

template<class T>
inline bool asMn(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T>
inline bool asMx(T& a, const T& b) { return a < b ? a = b, true : false; }
inline int nex(int i, int n) { return i == n - 1 ? 0 : i + 1; }
inline int pre(int i, int n) { return !i ? n - 1 : i - 1; }

const LL LL_INF = 1e18;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template<int MOD>
struct ModInt {
  int a;
  ModInt(int a_ = 0) {
    a = a_ < MOD ? (a_ < 0 ? a_ + MOD : a_) : a_ - MOD;
  }
  friend ostream& operator<<(ostream& os, const ModInt& o) {
    os << o.a;
    return os;
  }

  bool operator==(const ModInt& o) const { return a == o.a; }

  ModInt operator+(const ModInt& o) const { return ModInt(a + o.a); }
  ModInt operator-(const ModInt& o) const { return ModInt(a - o.a); }
  ModInt operator*(const ModInt& o) const { return ModInt(static_cast<int>(static_cast<LL>(a) * o.a % MOD)); }
  ModInt& operator+=(const ModInt& o) { return *this = *this + o; }
  ModInt& operator-=(const ModInt& o) { return *this = *this - o; }
  ModInt& operator*=(const ModInt& o) { return *this = *this * o; }
};
using Mint = ModInt<static_cast<int>(1e9 + 7)>;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

//  freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  int s, t; cin >> s >> t; --s; --t;
  vec<pair<int, int>, 2> adjEdge(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    adjEdge[u].emplace_back(v, w);
    adjEdge[v].emplace_back(u, w);
  }

  auto dijkstra = [&](int src) {
    vec<pair<LL, Mint>, 1> dist(n, pair<LL, Mint>{LL_INF, Mint()}); dist[src] = {0, Mint(1)};
    priority_queue<pair<LL, int>> pq; pq.emplace(-dist[src].first, src);
    while (sz(pq)) {
      LL curDist = -pq.top().first;
      int u = pq.top().second;
      pq.pop();

      if (curDist != dist[u].first) {
        continue;
      }

      for (auto& i : adjEdge[u]) {
        int v = i.first, w = i.second;
        if (asMn(dist[v].first, curDist + w)) {
          dist[v] = {curDist + w, dist[u].second};
          pq.emplace(-dist[v].first, v);
        } else if (dist[v].first == curDist + w) {
          dist[v].second += dist[u].second;
        }
      }
    }

    return dist;
  };
  auto distS = dijkstra(s), distT = dijkstra(t);

  vec<Mint, 1> a;
  for (int u = 0; u < n; ++u) {
    if ((distS[u].first << 1) == distS[t].first && (distT[u].first << 1) == distT[s].first) {
      a.emplace_back(distS[u].second * distT[u].second);
    } else {
      for (auto& i : adjEdge[u]) {
        int v = i.first, w = i.second;
        if (distS[u].first + w + distT[v].first == distS[t].first && (distS[u].first << 1) < distS[t].first && distS[t].first < (distS[v].first << 1)) {
          a.emplace_back(distS[u].second * distT[v].second);
        }
      }
    }
  }
  Mint sumA = accumulate(all(a), Mint());
  assert(sumA == distS[t].second);
  Mint ans;
  for (auto& i : a) {
    ans += i * (sumA - i);
  }

  cout << ans << '\n';

  return 0;
}
