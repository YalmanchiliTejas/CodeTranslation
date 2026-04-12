#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(0));
  for(int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<int> p(n-1);
  int ans = 0;
  iota(p.begin(), p.end(), 1);
  sort(p.begin(), p.end());
  do {
    int start = 0;
    bool ok = true;
    for(int i=0;i<n-1;i++) {
      if(find(G[start].begin(), G[start].end(), p[i]) == G[start].end()) {
        ok = false;
        break;
      } else {
        start = p[i];
      }
    }
    if(ok) ans++;
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
}