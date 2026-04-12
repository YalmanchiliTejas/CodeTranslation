#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a, b;
  bool G[10][10] = {};
  rep(i, m) {
    cin >> a >> b;
    a--, b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> v(n-1);
  rep(i, n-1) v[i] = i+1;
  sort(all(v));

  // 順列全列挙
  int ans = 0;
  do {
    int now = 0;
    rep(i, v.size()) {
      if(!G[now][v[i]]) break;
      now = v[i];
      if(i == v.size()-1) ans++;
    }
  } while(next_permutation(all(v)));

  cout << ans << '\n';
  return 0;
}
