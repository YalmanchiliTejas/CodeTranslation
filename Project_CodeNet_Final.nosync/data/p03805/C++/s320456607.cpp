#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> to[10];
int ans = 0;
const int nmax = 8;

void dfs(int v, int n, bool visited[nmax]) {
  visited[v]=1;
  bool all=1;
  rep(i,n){
    if(visited[i]==0)all=0;
  }
  ans += all;
  for (int u : to[v]) {
    if (visited[u]==1) continue;
    dfs(u,n,visited);
  }
  visited[v]=0;
}

int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  bool visited[nmax];
  dfs(0,n,visited);
  cout << ans << endl;
  return 0;
}
