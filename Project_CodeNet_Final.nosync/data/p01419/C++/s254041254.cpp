#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int INF = 10000000;
int main(){
  int R, C, M;
  cin >> R >> C >> M;
  vector<vector<char>> A(R + 2, vector<char>(C + 2, '#'));
  for (int i = 1; i <= R; i++){
    for (int j = 1; j <= C; j++){
      cin >> A[i][j];
    }
  }
  vector<vector<vector<int>>> P(R + 2, vector<vector<int>>(C + 2, vector<int>(3)));
  for (int i = 0; i < 3; i++){
    for (int j = 1; j <= R; j++){
      for (int k = 1; k <= C; k++){
        cin >> P[j][k][i];
      }
    }
  }
  vector<int> y(M), x(M);
  for (int i = 0; i < M; i++){
    cin >> y[i] >> x[i];
    y[i]++;
    x[i]++;
  }
  vector<pair<int, int>> p;
  p.push_back(make_pair(y[0], x[0]));
  for (int i = 0; i < M - 1; i++){
    vector<vector<bool>> used(R + 2, vector<bool>(C + 2, false));
    used[y[i]][x[i]] = true;
    vector<vector<pair<int, int>>> prev(R + 2, vector<pair<int, int>>(C + 2));
    queue<pair<int, int>> Q;
    Q.push(make_pair(y[i], x[i]));
    while (!Q.empty()){
      int cy = Q.front().first;
      int cx = Q.front().second;
      Q.pop();
      for (int j = 0; j < 4; j++){
        int y2 = cy + dy[j];
        int x2 = cx + dx[j];
        if (!used[y2][x2] && A[y2][x2] == '.'){
          used[y2][x2] = true;
          prev[y2][x2] = make_pair(cy, cx);
          Q.push(make_pair(y2, x2));
        }
      }
    }
    vector<pair<int, int>> tmp;
    tmp.push_back(make_pair(y[i + 1], x[i + 1]));
    while (1){
      tmp.push_back(prev[tmp.back().first][tmp.back().second]);
      if (tmp.back() == make_pair(y[i], x[i])){
        tmp.pop_back();
        break;
      }
    }
    reverse(tmp.begin(), tmp.end());
    for (auto c : tmp){
      p.push_back(c);
    }
  }
  int t = p.size();
  vector<vector<int>> prev(R + 2, vector<int>(C + 2, -1));
  long long ans = 0;
  for (int i = 0; i < t; i++){
    int cy = p[i].first;
    int cx = p[i].second;
    if (prev[cy][cx] == -1){
      ans += P[cy][cx][1] + P[cy][cx][2];
    } else {
      ans += min(P[cy][cx][1] + P[cy][cx][2], P[cy][cx][0] * (i - prev[cy][cx]));
    }
    prev[cy][cx] = i;
  }
  cout << ans << endl;
}
