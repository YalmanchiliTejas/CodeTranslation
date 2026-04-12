#include <bits/stdc++.h>
using namespace std;
using Vb = vector<bool>;
using G = vector<Vb>;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N, M;
  cin >> N >> M;

  G g(N, Vb(N, false));

  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u][v] = true;
    g[v][u] = true;
  }

  vector<int> p(N);
  rep(i, 0, N) p[i] = i;

  int ans = 0;
  do {
    if (p[0] != 0) break;
    bool ok = true;
    rep(i, 1, N) {
      if (!g[p[i - 1]][p[i]]) {
        ok = false;
        break;
      }
    }

    if (ok) ans++;
    // if (ok) {
    //   rep(i, 0, N) cout << p[i] << " ";
    //   cout << endl;
    // }
    
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}