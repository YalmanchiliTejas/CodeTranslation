#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<int> ord(N - 1);
  iota(ord.begin(), ord.end(), 1);
  
  int ans = 0;
  do {
    int now = 0;
    bool yes = true;
    for (int &i : ord) {
      for (auto &u : G[now]) if (u == i) {
        now = u;
        break;
      }
      yes &= now == i;
    }
    ans += yes;
  } while (next_permutation(ord.begin(), ord.end()));
  cout << ans << endl;

  return 0;
}