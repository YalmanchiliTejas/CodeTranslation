#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, a, b;
  cin >> n >> m;
  vector<set<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    a--; b--;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  vector<int> vert(n-1);
  iota(vert.begin(), vert.end(), 1);

  int res = 0;
  do {
    if (adj[0].find(vert[0]) == adj[0].end()) continue;
    bool ok = true;
    for (int i = 1; i < n-1; ++i) {
      if (adj[vert[i-1]].find(vert[i]) == adj[vert[i-1]].end()) {
        ok = false;
        break;
      }
    }
    if (ok) ++res;
  } while (next_permutation(vert.begin(), vert.end()));

  cout << res << endl;

  return 0;
}

