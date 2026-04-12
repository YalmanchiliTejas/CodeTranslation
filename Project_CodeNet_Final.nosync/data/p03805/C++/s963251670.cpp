#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int ans = 0;

void dfs(int k, vector<bool> &visited){
  // ベースケース
  // 全ての頂点を訪問済み
  bool ok = true;
  for(int i = 0; i < visited.size(); i++){
    if(i == k) continue;
    if(!visited.at(i)){
      ok = false;
    }
  }
  if(ok){
    ans++;
    return;
  }

  // 再帰ステップ
  // 隣接頂点が全て訪問済みとなるまでグラフを辿っていくことで、パスを列挙
  visited.at(k) = true;
  for(auto v: graph.at(k)){
      if(visited.at(v)) continue;
      dfs(v, visited);
  }
  visited.at(k) = false;
}

int main(){
  int N, M;
  cin >> N >> M;
  graph.assign(N, vector<int>());
  for(int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    graph.at(x).push_back(y);
    graph.at(y).push_back(x);
  }
  vector<bool> visited(N, false);
  dfs(0, visited);
  cout << ans  << endl;
}