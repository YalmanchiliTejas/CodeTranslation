#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

using graph = vector<vector<int>>;

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m);
  graph g(n);

  REP(i, m){
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
    g[a[i]].emplace_back(b[i]);
    g[b[i]].emplace_back(a[i]);
  }

  function<int(int, vector<bool>)> rec = [&](int s, vector<bool> vis){
    vis[s] = true;
    if(find(vis.begin(), vis.end(), false) == vis.end()) return 1;

    int ret = 0;
    for(const auto& next: g[s]){
      if(vis[next]) continue;
      ret += rec(next, vis);
    }

    return ret;
  };

  cout << rec(0, vector<bool>(n, false)) << endl;

  return 0;
}
