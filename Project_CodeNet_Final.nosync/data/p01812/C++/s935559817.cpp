#include <bits/stdc++.h>
using namespace std;
int INF = 1000;
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> D(M);
  for (int i = 0; i < M; i++){
    cin >> D[i];
    D[i]--;
  }
  vector<int> id(N, -1);
  for (int i = 0; i < M; i++){
    id[D[i]] = i;
  }
  vector<vector<int>> v(N, vector<int>(K));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < K; j++){
      cin >> v[i][j];
      v[i][j]--;
    }
  }
  int V = 1 << M;
  vector<vector<int>> E(V);
  for (int i = 0; i < V; i++){
    for (int j = 0; j < K; j++){
      int w = 0;
      for (int k = 0; k < M; k++){
        if (i >> k & 1){
          if (id[v[D[k]][j]] != -1){
            w |= 1 << id[v[D[k]][j]];
          }
        }
      }
      E[i].push_back(w);
    }
  }
  vector<int> d(V, INF);
  d[V - 1] = 0;
  queue<int> Q;
  Q.push(V - 1);
  while (!Q.empty()){
    int u = Q.front();
    Q.pop();
    for (int w : E[u]){
      if (d[w] == INF){
        d[w] = d[u] + 1;
        Q.push(w);
      }
    }
  }
  cout << d[0] << endl;
}
