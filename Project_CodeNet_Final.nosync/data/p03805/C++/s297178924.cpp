#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  set<pair<int, int>> SE;
  for (int a, b; cin >> a >> b;) {
    SE.insert({--a, --b});
    SE.insert({b, a});
  }
  vector<int> P(N);
  for (int i = 0; i < N; i++) P.at(i) = i;
  int ans = 0;
  do {
    if (P.at(0) != 0) continue;
    bool b = 1;
    for (int i = 0; i + 1 < N; i++) {
      if (!SE.count({P.at(i), P.at(i + 1)})) b = 0;
    }
    if (b) ans++;
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << "\n";
}