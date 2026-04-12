#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int D[16];
int v[110][110];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    cin >> D[i];
    D[i]--;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      cin >> v[i][j];
      v[i][j]--;
    }
  }

  int dist[1 << M];
  memset(dist, -1, sizeof(dist));
  dist[(1 << M) - 1] = 0;
  queue<int> que;
  que.emplace((1 << M) - 1);
  while (!que.empty()) {
    int curr = que.front(); que.pop();
    for (int $ = 0; $ < K; $++) {
      int next = 0;
      for (int i = 0; i < M; i++) {
        if (!(curr >> i & 1)) continue;
        int to = v[D[i]][$], id = -1;
        for (int j = 0; j < M; j++) {
          if (D[j] == to) id = j;
        }
        if (id < 0) continue;
        next |= 1 << id;
      }
      if (dist[next] >= 0) continue;
      dist[next] = dist[curr] + 1;
      que.emplace(next);
    }
  }
  cout << dist[0] << endl;

  return 0;
}
