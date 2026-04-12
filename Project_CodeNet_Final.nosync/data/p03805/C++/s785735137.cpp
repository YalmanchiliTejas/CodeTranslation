#include <bits/stdc++.h>
using namespace std;

static const int MAX_N = 8;

bool edges[MAX_N + 1][MAX_N + 1];

int main() {
  int N, M; cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a][b] = edges[b][a] = true;
  }

  int index[MAX_N];
  for (int i = 0; i < N; ++i) index[i] = i + 1;

  int ans{};

  sort(index, index + N); // 昇順にソートしておく
  do {
    bool path{true};
    for (int i{1}; i < N; ++i) {
      if (!edges[index[i - 1]][index[i]]) {
        path = false;
        break;
      }
    }
    if (path) ++ans;
  } while (next_permutation(index + 1, index + N));

  cout << ans << endl;
  return 0;
}
