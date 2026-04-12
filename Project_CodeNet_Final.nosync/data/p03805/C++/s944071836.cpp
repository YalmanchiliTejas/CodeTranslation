#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

static constexpr int MAX_N{8};
bool edges[MAX_N + 1][MAX_N + 1];
int perm[]{1, 2, 3, 4, 5, 6, 7, 8};

int N, M;

int main() {
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a][b] = edges[b][a] = true;
  }

  int ans{};
  do {
    bool path{true};
    for (int i{}; i < N - 1 && path; ++i) {
      int v1 = perm[i];
      int v2 = perm[i+1];
      if (!edges[v1][v2]) {
        path = false;
      }
    }
    if (path)
      ++ans;
  } while (next_permutation(perm + 1, perm + N));

  cout << ans << endl;
}
