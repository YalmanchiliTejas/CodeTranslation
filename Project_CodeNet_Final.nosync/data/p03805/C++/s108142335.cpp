#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> v;
  for (int i = 0; i < N; i++) {
    v.push_back(i+1);
  }

  int a, b;
  map<int, set<int>> Mp;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    Mp[a].insert(b);
    Mp[b].insert(a);
  }

  int ans = 0;
  do {
    if (v[0] != 1) continue;
    int x = 1;
    for (int i = 0; i < N-1; i++) {
      a = v[i];
      b = v[i+1];
      if (Mp[a].count(b) == 0) {
        x = 0;
        break;
      }
    }
    ans += x;
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}