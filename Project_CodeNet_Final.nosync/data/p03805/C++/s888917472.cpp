#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

vector<vector<int>> g;
int ans = 0;
int n, m;

void dfs(int v, int c, vector<int> visited) {
  visited[v] = 1;
  c++;
  if (c == n){
    bool ok = true;
    rep(i, n) if (!visited[i]) ok = false;
    if (ok) ans++;
    return;
  } 
  rep(i, g[v].size()) {
    int u = g[v][i];
    if (visited[u]) continue;
    dfs(u, c, visited);
  }
}

int main(){
  cin >> n >> m;
  g.resize(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> x(n, 0);
  dfs(0, 0, x);
  cout << ans << endl;
}
