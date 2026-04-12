#include <bits/stdc++.h>
using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];

int main() {
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B; cin >> A >> B;
    graph[A-1][B-1] = graph[B-1][A-1] = true;
  }
  vector<int> nodes(N);
  for (int i = 0; i < N; i++) nodes[i] = i;
  int cnt = 0;
  do {
    bool flag = true;
    if (nodes[0] != 0) continue;
    for (int i = 0; i < N-1; i++) {
      if (graph[nodes[i]][nodes[i+1]] == false) flag = false; continue;
    }
    if (flag) cnt++;
  } while (next_permutation(nodes.begin(), nodes.end()));
  cout << cnt << endl;
  return 0;
}