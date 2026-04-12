#include <bits/stdc++.h>
using namespace std;

bool graph[8][8];

int dfs(int v, int N, bool visited[8]) {
  
  // 全ての点にいけるか否かの確認
  bool all = true;

  for (int i = 0; i < N; i++) {
    if (visited[i] == false) {
      all = false;
    }
  }

  // 全ての点にいける場合は、回答に1（パターン）を追加する
  if (all){
    return 1;
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    if (graph[v][i] == false) {
      continue;
    }
    if (visited[i]) {
      continue;
    }
    
    // 点iを訪問済みとした場合
    visited[i] = true;
    
    // 点iから次のdfs 
    result += dfs(i, N, visited);

    // 点iを未訪問にした場合
    visited[i] = false;

  }

  return result;

}


int main() {

  int N, M;
  cin >> N >> M;
  
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    graph[a - 1][b - 1] = true;
    graph[b - 1][a - 1] = true;
  }

  bool visited[8];
  for (int i = 0; i < N; i++) {
    visited[i] = false;
  }

  // 1からスタートする
  visited[0] = true;

  int answer = dfs(0, N, visited);

  cout << answer <<  endl;

  return 0;

}