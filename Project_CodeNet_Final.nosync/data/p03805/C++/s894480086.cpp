#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using Node = vector<int>;
using Graph = vector<Node>;

int main (void) {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  REP (i, M) {
    int a, b;
    cin >> a >> b;
    // 0-index;
    a -= 1;
    b -= 1;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  stack<pair<int, int>> st;
  st.push(make_pair(1, 0));
  int ans = 0;
  while (!st.empty()) {
    int visited, now;
    tie(visited, now) = st.top(); st.pop();
    // cout << visited << "," << now << endl;
    if (visited == (1 << N) - 1) {
      ans++;
      continue;
    }
    for (int& next : G[now]) {
      if ((visited & (1 << next)) == 0) {
        int new_visited = visited | (1 << next);
        // cout << "new: ";
        // cout << new_visited << "," << next << endl;
        st.push(make_pair(new_visited, next));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
