#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> connected(n, vector<bool>(n));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    connected.at(a - 1).at(b - 1) = true;
    connected.at(b - 1).at(a - 1) = true;
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) v.at(i) = i;
  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (!connected.at(v.at(i)).at(v.at(i + 1))) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  } while (next_permutation(v.begin() + 1, v.end()));
  cout << ans << endl;
}
