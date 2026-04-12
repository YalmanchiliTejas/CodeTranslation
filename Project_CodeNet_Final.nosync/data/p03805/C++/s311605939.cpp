#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> G(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(a-1).at(b-1) = true;
    G.at(b-1).at(a-1) = true;
  }
  vector<int> route(N);
  for (int i = 0; i < N; i++) route.at(i) = i;
  int ans = 0;
  do {
    if (route.at(0) != 0) break;
    bool flag = true;
    for (int i = 0; i+1 < N; i++) {
      int now = route.at(i);
      int next = route.at(i+1);
      if (!G.at(now).at(next)) flag = false;
    }
    if (flag) ans++;
  } while (next_permutation(route.begin(), route.end()));
  cout << ans << endl;
}