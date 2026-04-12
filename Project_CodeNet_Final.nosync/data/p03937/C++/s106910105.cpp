#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  int h, w; std::cin >> h >> w;
  string grid[h]; rep(i, h) std::cin >> grid[i];
  bool isPossible = true;
  int cnt = 0;
  rep(i, h) rep(j, w) cnt += (grid[i][j] == '#');
  if (cnt != h + w - 1) isPossible = false;
  vi que;
  que.pb(0);
  rep(i, que.size()) {
    int x = que[i] % w, y = que[i] / w;
    grid[y][x] = '.';
    srep(dx, -1, 2) srep(dy, -1, 2) {
      int nx = x+dx, ny = y+dy;
      if (dx * dx + dy * dy != 1) continue;
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (grid[ny][nx] == '.') continue;
      if (nx == -1 || ny == -1) isPossible = false;
      que.pb(ny * w + nx);
    }
  }
  std::cout << (isPossible ? "Possible" : "Impossible") << "\n";
}
