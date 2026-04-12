#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int connected_components_count(vector<vector<int>> &E){
  int N = E.size();
  vector<bool> used(N, false);
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (!used[i]){
      used[i] = true;
      ans++;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
  }
  return ans;
}
struct biconnected_components{
  int N;
  vector<vector<int>> E;
  vector<bool> is_articulation_point;
  biconnected_components(vector<vector<int>> E): E(E){
    N = E.size();
    is_articulation_point = vector<bool>(N, false);
    for (int i = 0; i < N; i++){
      vector<vector<int>> E2(N);
      for (int j = 0; j < N; j++){
        for (int k : E[j]){
          if (j != i && k != i){
            E2[j].push_back(k);
          }
        }
      }
      if (connected_components_count(E2) > 2){
        is_articulation_point[i] = true;
      }
    }
  }
  bool same(int x, int y1, int y2, int y3){
    for (int i = 0; i < N; i++){
      if (i != x && i != y1 && i != y2 && i != y3){
        if (!is_articulation_point[i]){
          continue;
        }
        vector<vector<int>> E2(N);
        for (int j = 0; j < N; j++){
          for (int k : E[j]){
            if (j != i && k != i){
              E2[j].push_back(k);
            }
          }
        }
        vector<bool> used(N, false);
        used[x] = true;
        queue<int> Q;
        Q.push(x);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E2[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        if (!used[y1] || !used[y2] || !used[y3]){
          return false;
        }
      }
    }
    return true;
  }
};
int main(){
  while (1){
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0){
      break;
    }
    vector<vector<char>> c(N, vector<char>(M));
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        cin >> c[i][j];
      }
    }
    vector<vector<bool>> used(N, vector<bool>(M, false));
    used[0][0] = true;
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()){
      int y = Q.front().first;
      int x = Q.front().second;
      Q.pop();
      for (int i = 0; i < 4; i++){
        int y2 = y + dy[i];
        int x2 = x + dx[i];
        if (0 <= y2 && y2 < N && 0 <= x2 && x2 < M){
          if (!used[y2][x2] && c[y2][x2] == '.'){
            used[y2][x2] = true;
            Q.push(make_pair(y2, x2));
          }
        }
      }
    }
    if (!used[0][M - 1] || !used[N - 1][0] || !used[N - 1][M - 1]){
      cout << "NO" << endl;
    } else {
      for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
          if (!used[i][j]){
            c[i][j] = '#';
          }
        }
      }
      int cnt = 0;
      vector<vector<int>> id(N, vector<int>(M, -1));
      for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
          if (c[i][j] == '.'){
            id[i][j] = cnt;
            cnt++;
          }
        }
      }
      vector<vector<int>> E(cnt);
      for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
          if (c[i][j] == '.'){
            for (int k = 0; k < 4; k++){
              int y = i + dy[k];
              int x = j + dx[k];
              if (0 <= y && y < N && 0 <= x && x < M){
                if (c[y][x] == '.'){
                  E[id[i][j]].push_back(id[y][x]);
                }
              }
            }
          }
        }
      }
      //biconnected-components decomposition
      biconnected_components C(E);
      int a = id[0][0];
      int b = id[0][M - 1];
      int c = id[N - 1][0];
      int d = id[N - 1][M - 1];
      if (C.same(a, b, c, d)){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
