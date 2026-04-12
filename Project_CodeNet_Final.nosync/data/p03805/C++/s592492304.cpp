#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> bridge(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    bridge.at(i) = make_pair(a, b);
  }
  int total = 0;
  vector<int> line(N);
  for (int i = 0; i < N; i++) {
    line.at(i) = i + 1;
  }
  sort(line.begin(), line.end());
  do {
    if (line.at(0) == 1) {
      for (int i = 0; i < N - 1; i++) {
        bool able = false;
        for (int j = 0; j < M; j++) {
          if (bridge.at(j) == make_pair(line.at(i), line.at(i + 1)) || bridge.at(j) == make_pair(line.at(i + 1), line.at(i))) {
            able = true;
            break;
          }
        }
        if (!able) {
          break;
        }
        if (i == N - 2) {
          total += 1;
        }
      }
    }
  } while (next_permutation(line.begin(), line.end()));
  cout << total << endl;     
}
