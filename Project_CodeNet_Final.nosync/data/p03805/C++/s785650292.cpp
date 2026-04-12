#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> path(n, vector<int>(n));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    path[a][b] = 1;
    path[b][a] = 1;
  }

  vector<int> ord;
  rep(i, n) {
    ord.push_back(i);
  }

  int ans = 0;
  do
  {
    if (ord[0] != 0) break;

    bool ok = true;
    rep(i, n - 1){
      if (path[ord[i]][ord[i + 1]] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  } while (next_permutation(ord.begin(), ord.end()));

  cout << ans << endl;
}