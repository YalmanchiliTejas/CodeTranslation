#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

bool fg ;
int dfs(const Graph &G,vector<bool> seen, int v) {
    seen[v] = true; // v を訪問済にする
    fg =true;
    for (int a=0;a<seen.size();a++){
      if(!seen[a]) fg=false;
    }
    if(fg) return 1;
  
    int total=0;

    // v から行ける各頂点 i について
    for (int i=0; i<seen.size();i++){
        if(!G[v][i])continue;
        if(seen[i])continue;
        seen[i]=true;
        total += dfs(G, seen, i); // 再帰的に探索
        seen[i]=false;
    }
    return total;
}

int main(){
  
  //入力・準備
  int N; int M;
  cin >> N >> M;
  Graph G(N, vector<int>(N));;
  for(int i=0;i<M;i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b]=1;
    G[b][a]=1;
  }
  
  //実装
  vector<bool> seen;
  seen.assign(N,false);
  cout << dfs(G,seen,0) << endl;
  
}