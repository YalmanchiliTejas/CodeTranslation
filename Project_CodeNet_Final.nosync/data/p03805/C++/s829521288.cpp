#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using Graph = vector<vector<bool>>;
int ans=0;
int N,M;

// 深さ優先探索
void dfs(const Graph &G, int v,vector<int> seen) {
    seen[v] = 1; // v を訪問済にする
    if(accumulate(seen.begin(),seen.end(),0)==N)ans++;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
  vector<int> perm;
  for(int i=1; i<N; i++){
    perm.push_back(i);
  }
    Graph G(N,vector<bool>(N,false));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
      a--;b--;
        G[a].at(b) = true;
        G[b].at(a) = true;
    }
  do{
      if(!G[0].at(perm.at(0))){continue;}
    for(int i=0; i<N-1; i++){
      if(i==(N-2)){ans++;break;}
      if(G[perm.at(i)].at(perm.at(i+1))){continue;}
      else{break;}
    }
  }while(next_permutation(perm.begin(),perm.end()));
    // 頂点 0 をスタートとした探索
  //vector<int> seen;
    //seen.assign(N, 0); // 全頂点を「未訪問」に初期化
    //dfs(G, 0, seen);
  cout << ans << endl;
}