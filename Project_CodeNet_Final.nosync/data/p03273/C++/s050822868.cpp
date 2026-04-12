#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

char a[105][105];
int r[105][105], c[105][105];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    r[i][0] = 1;
  }
  for (int j = 1; j <= m; j++) {
    c[0][j] = 1;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == '#') continue;
    r[i][j] = r[i][j - 1];
    c[i][j] = c[i - 1][j];
  }
  /*for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cout << r[i][j] << " \n"[j == m];
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    cout << c[i][j] << " \n"[j == m];
  }*/
  for (int i = 1; i <= n; i++) {
    if (r[i][m]) continue;
    for (int j = 1; j <= m; j++) {
      if (c[n][j]) continue;
      cout << a[i][j];
    }
    cout << '\n';
  }
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
