#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  int a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }    
  bool e[n][n]; memset(e, 0, sizeof(e));
  for (int i = 0; i < m; i++) e[a[i]][b[i]] = e[b[i]][a[i]] = 1;
  int res = 0;
  int path[n];
  for (int i = 0; i < n; i++) path[i] = i;
  do {
    bool f = 1;
    for (int i = 0; i < n - 1; i++) if (!e[path[i]][path[i + 1]]) f = 0;
    res += f;
  } while (next_permutation(path + 1, path + n));
  cout << res << "\n";
  return 0;
}