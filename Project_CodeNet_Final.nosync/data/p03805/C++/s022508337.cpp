#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> check(n, vector<bool>(m, false));
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b; a--; b--;
    check[a][b] = check[b][a] = true;
  }

  vector<int> ord(n);
  for (int i = 0; i < n; i++) {
    ord[i] = i;
  }

  int ans = 0;
  do {
    if (ord[0] != 0) break;

    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      int from = ord[i];
      int to = ord[i+1];
      if(!check[from][to]) ok = false;
    }
    if(ok) ans++;
  } while (next_permutation(ord.begin(), ord.end()));
  cout << ans << endl;
}