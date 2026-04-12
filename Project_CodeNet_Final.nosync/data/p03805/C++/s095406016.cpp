#include <vector>
#include <iostream>

using namespace std;

vector<int> color;
int N;

int rec(const vector<vector<int> > &graph, int n, int depth) {
  if (depth == N) {
    return 1;
  }

  int sum = 0;
  for (auto t : graph[n]) {
    if (color[t]) continue;
    color[t] = 1;
    sum += rec(graph, t, depth + 1);
    color[t] = 0;
  }
  return sum;
}

int main() {
  int M;
  cin >> N;
  cin >> M;
  int a, b;
  color = vector<int>(N, 0);
  color[0] = 1;
  vector<vector<int> > graph(N);
  for (int i = 0; i < M; ++i) {
    cin >> a;
    cin >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  printf("%d\n", rec(graph, 0, 1));
  return 0;
}