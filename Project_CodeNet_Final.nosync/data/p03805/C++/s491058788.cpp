#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef long long ll;

vector<vector<int>> G(10);
int ans = 0;
int n, m;

void dfs(int now, vector<bool> &visited) {

  visited[now] = true;

  bool stop = true;
  for (int i = 0; i < G[now].size(); i++) {
    if (!visited[G[now][i]]) stop = false;
  }
  if (stop) {
    bool ok = true;
    rep (i, n) {
      if (!visited[i]) {
        ok = false;
      }
    }
    if (ok) ans++;
    return ;
  }
  
  for (int i = 0; i < G[now].size(); i++) {
    if (!visited[G[now][i]]) {
      dfs(G[now][i], visited);
      visited[G[now][i]] = false;
    }
  }
}

int main(void) {
  
  cin >> n >> m;

  

  rep (i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> visited(n, false);
  dfs(0, visited);

  cout << ans << endl;

  return 0;
}
