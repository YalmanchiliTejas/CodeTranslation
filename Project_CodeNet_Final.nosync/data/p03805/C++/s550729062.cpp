#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0, a, b; cin >> a >> b; i++) {
    G.at(--a).push_back(--b), G.at(b).push_back(a);
  }
  vector<int> P(N);
  for (int i = 0; i < N; i++) P.at(i) = i;
  int ans = 0;
  do {
    if (P.at(0) != 0) break;
    int i = 0;
    while (i < N - 1) {
      bool next = 0;
      for (auto g : G.at(P.at(i))) if (g == P.at(i + 1)) next = 1;
      if (next) i++;
      else break;
    }
    if (i == N - 1) ans++;
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << "\n";
}