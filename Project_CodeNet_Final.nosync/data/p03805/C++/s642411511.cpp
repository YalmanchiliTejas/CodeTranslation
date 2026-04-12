#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using ll = long long;
using namespace std;
using P = pair<ll, ll>;
static ll imin = std::numeric_limits<ll>::min() / 10;
static ll imax = std::numeric_limits<ll>::max() / 10;
#define rep(i, n) for (ll i = 0; (i) < (n); ++(i))
#define rep1(i, n) for (ll i = 1; (i) < (n); ++(i))
#define rev_rep(i, n) for (ll i = (n)-1; (i) >= 0; --(i))
#define range(a, i, b) for (ll i = (a); (i) < (b); ++(i))

#ifdef LOCAL
#define dump(x) cout << #x << ":" << x << "\n";
#endif
#ifndef LOCAL
#define dump(x)
#endif

#define all(v) v.begin(), v.end()
#define readl(N) \
  ll N;          \
  cin >> N;
#define readlv(N, vec) \
  vector<ll> vec(N);   \
  rep(i, N) { cin >> vec[i]; }
#define greater_than [](ll l, ll r) { return l > r; }
template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, std::map<T1, T2>& mp);
template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2>& pair);
template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec);
template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2>& pair) {
  os << '(' << pair.first << ',' << pair.second << ')';
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
  std::size_t n = vec.size();
  if (n == 0) {
    return os;
  }
  os << " ";
  for (ll i = 0; i < n - 1; ++i) {
    os << vec[i] << " ";
  }
  os << vec[n - 1];
  os << std::endl;
  return os;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, std::map<T1, T2>& mp) {
  std::size_t n = mp.size();
  if (n == 0) {
    return os;
  }
  os << " ";
  for (auto&& x : mp) {
    os << x << " ";
  }
  os << std::endl;
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, std::set<T>& mp) {
  std::size_t n = mp.size();
  if (n == 0) {
    return os;
  }
  os << " ";
  for (auto&& x : mp) {
    os << x << " ";
  }
  os << std::endl;
  return os;
}

template <class T>
inline bool chmin(T& a, T const b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T const b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll fact(ll n) {
  ll res = 1;
  while (n > 0) {
    res *= n;
    n--;
  }
  return res;
}

ll pow(ll i, ll n) {
  ll res = 1;
  while (n >= 0) {
    res *= i;
    n--;
  }
  return res;
}

ll gcd(ll l, ll r) {
  if (l < r) {
    return gcd(r, l);
  }
  if (r == 0) {
    return l;
  }
  return gcd(r, l % r);
}

template <class T>
vector<T> accum_sum(vector<T> const& a) {
  vector<T> b(a.size() + 1);
  b[0] = 0;
  rep(i, a.size()) { b[i + 1] = b[i] + a[i]; }
  return b;
}
constexpr ll mod = 1e9 + 7;
ll N, M;
vector<P> ars;
map<ll, bool> visited;
ll res = 0;
void dfs(ll current) {
  dump(current);
  bool allvisited = true;
  for (auto&& x : visited) {
    allvisited = allvisited && x.second;
  }
  if (allvisited) {
    dump("inc");
    res++;
    return;
  }
  rep(i, N) {
    for (auto&& arr : ars) {
      if (((arr.first == i && arr.second == current) ||
           (arr.first == current && arr.second == i)) &&
          !visited[i]) {
        visited[i] = true;
        dfs(i);
        visited[i] = false;
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  cin >> N >> M;
  ars.resize(M);
  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    ars[i].first = a;
    ars[i].second = b;
  }

  rep(i, N) { visited[i] = false; }
  visited[0] = true;
  dfs(0);
  cout << res << endl;
  return 0;
}
