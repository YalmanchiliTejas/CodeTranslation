#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> P;
typedef vector<int> V;
const int MAX_SIZE = 50;
const int MAX_TASK_SIZE = 1000;

vector<P> dfs(char f[MAX_SIZE][MAX_SIZE], P src, P des, int R, int C) {
  vector<P> v;
  if (src == des) {
    v.push_back(des);
    return v;
  }
  f[src.first][src.second] = '@';
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  for (int k = 0; k < 4; ++k) {
    int i = src.first  + dr[k];
    int j = src.second + dc[k];
    if (i + 1 && j + 1 && i < R && j < C && f[i][j] == '.') {
      v = dfs(f, P(i, j), des, R, C);
      if (v.size()) {
        v.insert(v.begin(), src);
        break;
      }
    }
  }
  f[src.first][src.second] = '.';
  return v;
}

int calc(int R, int C, int M, char f[][MAX_SIZE], int costs[][MAX_SIZE][MAX_SIZE], P tasks[]) {
  map<P, V> m;
  int t = 0;
  m.insert(pair<P, V>(tasks[0], V(1, t++)));
  for (int i = 0; i < M - 1; ++i) {
    vector<P> v = dfs(f, tasks[i], tasks[i + 1], R, C);
    for (vector<P>::iterator vit = ++v.begin(); vit != v.end(); ++vit) {
      map<P, V>::iterator it = m.find(*vit);
      if (it == m.end()) {
        m.insert(pair<P, V>(*vit, V(1, t++)));
      } else {
        it->second.push_back(t++);
      }
    }
  }
  int a = 0;
  for (map<P, V>::iterator it = m.begin(); it != m.end(); ++it) {
    int i = it->first.first, j = it->first.second;
    V v = it->second;
    int l = v.size();
    for (int k = 0; k < l; ++k) {
      int c = costs[1][i][j] + costs[2][i][j];
      if (k < l - 1) {
        a += min(c, (v[k + 1] - v[k]) * costs[0][i][j]);
      } else {
        a += c;
      }
    }
  }
  return a;
}

int main() {
  int n;
  int R, C, M;
  char f[MAX_SIZE][MAX_SIZE];
  int costs[3][MAX_SIZE][MAX_SIZE];
  P tasks[MAX_TASK_SIZE];
  char s[MAX_SIZE + 1];
  cin >> R >> C >> M;
  for (int i = 0; i < R; ++i) {
    cin >> s;
    for (int j = 0; j < C; ++j) {
      f[i][j] = s[j];
    }
  }
  for (int k = 0; k < 3; ++k) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> n;
        costs[k][i][j] = n;
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    int r, c;
    cin >> r >> c;
    tasks[i] = P(r, c);
  }
  cout << calc(R, C, M, f, costs, tasks) << endl;
}