#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;

bool check(vector<int> &v, vector<vector<bool>> &paths, int &N) {
  rep(i, N - 1) {
    int a = v.at(i), b = v.at(i + 1);
    if (!paths.at(a).at(b)) return false;
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<bool>> paths(N + 1, vector<bool>(N + 1, false));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    paths.at(a).at(b) = true;
    paths.at(b).at(a) = true;
  }

  int ans = 0;

  vector<int> v(N, 1);
  iota(next(v.begin()), v.end(), 2);
  do {
    if (check(v, paths, N)) ans++;
  } while (next_permutation(next(v.begin()), v.end()));

  cout << ans << endl;
  return 0;
}
