#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int N, M, ans = 0;
vector<vector<int>> v;

void dfs(int i, int p, vector<bool> vis) {
  if (i == N - 1) {
    ans++;
    return;
  }

  for (auto vv : v[p]) {
    vector<bool> viss = vis;
    if (viss[vv])
      continue;
    viss[vv] = true;
    dfs(i + 1, vv, viss);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  v.resize(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<bool> vis(N, false);
  vis[0] = true;
  dfs(0, 0, vis);
  cout << ans << endl;
}
