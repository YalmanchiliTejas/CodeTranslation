#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  int n, m;
  cin >> n >> m;
  int g[n][n] = {};
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a][b] = 1;
    g[b][a] = 1;
  }

  vector<int> v(n);
  rep(i, n) v[i] = i;

  int ans = 0;

  do {
    bool is_ok = true;
    rep(i, n-1) {
      if (g[v[i]][v[i+1]] == 0) {
        is_ok = false;
        break;
      }
    }

    if (is_ok) ans++;

  } while(next_permutation(v.begin() + 1, v.begin() + n));

  cout << ans << endl;



  return 0;
}
