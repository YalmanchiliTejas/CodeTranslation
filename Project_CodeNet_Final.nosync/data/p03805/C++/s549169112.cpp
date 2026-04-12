#include<bits/stdc++.h>

using namespace std;

int count(int now, int depth, vector<vector<bool>>& graph, vector<bool>& used){
  int n = (int)graph.size();
  if(n == depth) return 1;
  int ret = 0;
  for(int i = 0; i < n; i++){
    if(!used[i] && graph[now][i]){
      used[i] = true;
      ret += count(i, depth + 1, graph, used);
      used[i] = false;
    }
  }
  
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> graph(N, vector<bool>(N, false));
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a][b] = graph[b][a] = true;
  }
  
  vector<bool> used(N, false);
  used[0] = true;
  cout << count(0, 1, graph, used) << endl;
  
  return 0;
}