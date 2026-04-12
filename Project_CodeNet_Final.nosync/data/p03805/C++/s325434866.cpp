#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int a[m], b[m];
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < m; i++) {
    a[i]--; b[i]--;
  }
  bool e[n][n];
  memset(e, false, sizeof(e));
  for (int i = 0; i < m; i++) {
    e[a[i]][b[i]] = e[b[i]][a[i]] = true;
  }
  int res = 0;
  int v[n];
  for (int i = 0; i < n; i++) v[i] = i;
  do {
    bool t = true;
    for (int i = 0; i < n - 1; i++) {
      if (!e[v[i]][v[i + 1]]) {
        t = false;
        break;
      }
    }
    res += t; 
  } while (next_permutation(v + 1, v + n));
  cout << res << "\n";
  return 0;
}