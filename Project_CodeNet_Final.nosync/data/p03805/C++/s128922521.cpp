#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int INF = 1000000007;

// 辺に重みをつける場合
/* 
struct Edge{
  int to;
  int weight;
  Edge(int t,int w) : to(t). weight(w) { }
};
*/

using Graph = vector<vector<int>>;
// using Graph = vector<vector<Edge>>;

int res = 0;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
  bool end = true;
  for (int i = 0; i < seen.size(); ++i) if (!seen[i] && i != v) end = false;
  if (end) {
      ++res;
      return;
  }

  seen[v] = true; // v を訪問済みにする

  // vから行ける各頂点 next_v について
  for(auto next_v : G[v]){
    if (seen[next_v]) continue; // next_v が探索済みだったらスルー
    dfs(G, next_v); // 再帰的に探索
  }
  seen[v] = false;
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  
  Graph G(N);
  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  seen.assign(N, false); // 全頂点を「未訪問」にして初期化
  dfs(G, 0);

  cout << res << endl;

}