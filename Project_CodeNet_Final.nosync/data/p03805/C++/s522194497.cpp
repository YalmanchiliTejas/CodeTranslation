#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  vector<pair<int, int>> ab(M);
  rep (i, M) {
    cin >> a >> b;
    ab[i] = make_pair(a, b);
  }
  vector<int> path(N);
  rep(i, N) path[i] = i + 1;
  int result = 0;
  do {
    if (path.end() == adjacent_find(all(path), [&](int l, int r) {
      return none_of(all(ab), [&](auto p) {
        return ((p.first  == l) && (p.second == r)) ||
               ((p.second == l) && (p.first  == r));
        });
      })) {
      ++result;
    }
  } while (next_permutation(path.begin() + 1, path.end()));
  cout << result << endl;
  return 0;
}
