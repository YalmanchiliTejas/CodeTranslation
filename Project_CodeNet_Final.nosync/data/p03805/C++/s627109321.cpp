//In The Name Of Allah
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define double long double 
#define fi first
#define se second
#define pii pair<int, int>

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u][v] = adj[v][u] = 1;
  }
  int ans = 0;
  vector<int> per;
  for (int i = 1; i < n; i++) {
    per.push_back(i);
  }
  do {
    bool is_ans = adj[0][per[0]];
    for (int i = 1; i < sz(per); i++) {
      if (!adj[per[i]][per[i - 1]]) is_ans = false;
    }
    if (is_ans) ans++;
  } while(next_permutation(per.begin(), per.end()));
  cout << ans << "\n";
}

