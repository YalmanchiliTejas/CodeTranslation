#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int N = 10;

vector<int> adj[N];

int n, m, ans = 0;
int vst[N];

void dfs(int i, int c = 1) {
  if (c == n) ans++;
  vst[i] = 1;
  for (auto &j : adj[i]) {
    if (!vst[j]) dfs(j, c + 1);
  }
  vst[i] = 0;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
