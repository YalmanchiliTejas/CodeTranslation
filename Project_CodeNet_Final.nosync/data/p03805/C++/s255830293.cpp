#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;

bool G[10][10];

int dfs(int v,int n, bool visited[10]){
  bool ok = true;

  rep(i,n){
    if(visited[i]==false) ok = false;
  }
  if(ok) return 1;

  int ret = 0;
  rep(i,n){
    if(G[v][i]==false) continue;
    if(visited[i]) continue;

    visited[i]=true;
    ret+=dfs(i,n,visited);
    visited[i]=false;
  }
  return ret;
}
int main() {
  int n,m; cin >> n >> m;
  rep(i,m){
    int a, b; cin >> a >> b; --a,--b;
    G[a][b]=G[b][a]=true;
  }
  bool visited[10];
  rep(i,n){
    visited[i]=false;
  }
  visited[0]=true;
  cout << dfs(0,n,visited) << endl;
  return 0;
}