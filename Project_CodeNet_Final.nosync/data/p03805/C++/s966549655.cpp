#include <bits/stdc++.h>

using namespace std;

int N, M;
bool G[10][10];

bool CanVisitAllVertex(const vector<int> &vertexOrders) {
  for (int i = 0; i < N - 1; i++) {
    int current = vertexOrders[i];
    int next = vertexOrders[i + 1];
    if (!G[current][next]) {
      return false;
    }
  }
  return true;
}

int main() {
  memset(G, false, sizeof(G));

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> vertexOrders;
  for (int i = 0; i < N; i++) {
    vertexOrders.push_back(i);
  }

  int count = 0;
  do {
    if (CanVisitAllVertex(vertexOrders)) {
      count++;
    }
  } while (next_permutation(vertexOrders.begin() + 1, vertexOrders.end()));

  printf("%d\n", count);

  return 0;
}
