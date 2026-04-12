#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rep2(i, a, b) for(int i=a; i<=(int)(b); ++i)
#define all(v) v.begin(),v.end()

vector<vector<int>> g;

int n, ans;

void dfs(int u, unordered_set<int> s) {
  s.insert(u);
  if (s.size() == n) ++ans;
  for (int to : g[u]) {
    if (s.count(to)) continue;
    dfs(to, s);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int m;
  cin >> n >> m;
  g.resize(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  unordered_set<int> s;
  dfs(0, s);
  cout << ans << endl;
}