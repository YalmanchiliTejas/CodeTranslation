#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<int> perm(N - 1);
  for (int i = 0; i < perm.size(); ++i) {
    perm[i] = i + 1;
  }

  int ans = 0;
  do {
    bool ok = true;
    int old = 0;
    rep(i, perm.size()) {
      if (find(v[old].begin(), v[old].end(), perm[i]) == v[old].end()) {
        ok = false;
        break;
      }
      old = perm[i];
    }
    if (ok) ++ans;
  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans << endl;
  
  return 0;
}