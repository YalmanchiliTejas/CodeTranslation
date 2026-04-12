#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N, M;
vector<vector<int>> g;
vector<int> homon;
int ans = 0;
int check(){
  REP(i, N){
    if(homon[i] == 0){
      return 0;
    }
  }
  return 1;
}

void dfs(int c, int depth){
  if(depth == N){
    ans += check();
    return;
  }
  REP(i, g[c].size()){
    int next = g[c][i];
    if(homon[next] == 0){
      homon[next] = 1;
      dfs(next, depth+1);
      homon[next] = 0;
    }
  }
  return ;
}
int main(){
  cin >> N >> M;
  g.resize(N);
  homon.resize(N, 0);

  REP(i, M){
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  homon[0] = 1;
  dfs(0, 1);

  cout << ans << endl;

  return 0;
}
