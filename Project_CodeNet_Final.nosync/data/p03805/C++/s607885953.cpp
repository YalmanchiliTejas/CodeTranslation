#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int n;
vector<vector<int>> g(10);
bool visited[10] = {};

int dfs(int x, int cnt) {
  if (cnt == n) return 1;

  int ret = 0;
  for (auto nx: g[x]) {
    if (visited[nx]) continue;
    visited[nx] = true;
    ret += dfs(nx, cnt+1);
    visited[nx] = false;
  }
  return ret;
}

int main() {
  int m; cin>>n>>m;
  rep(i, m) {
    int a, b; cin>>a>>b;
    --a; --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  visited[0] = true;
  print(dfs(0, 1));

  return 0;
}
