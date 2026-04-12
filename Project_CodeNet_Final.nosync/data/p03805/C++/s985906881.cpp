#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;


bool g[10][10];

int main() {
  int n,m;
  cin >> n >> m;

  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a][b] = true;
    g[b][a] = true;
  }

  std::vector<int> v(n);
  rep(i,n) v[i] = i;

  int ans = 0;
  do {
    if (v[0] != 0) break;

    bool ok = true;
    rep(i,n-1) {
      if (!g[v[i]][v[i+1]]) {
        ok = false;
      }
    }
    if (ok) ans++;
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
}
