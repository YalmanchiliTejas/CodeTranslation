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
    if (P.at(0) != 0) continue;
    int now = 0;
    for (; now < N - 1;) {
      bool next = false;
      for (auto g : G.at(P.at(now))) if (g == P.at(now + 1)) next = true;
      if (next) {
        now++;
        if (now == N - 1) ans++;
      } else {
        break;
      }
    }
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << "\n";
}