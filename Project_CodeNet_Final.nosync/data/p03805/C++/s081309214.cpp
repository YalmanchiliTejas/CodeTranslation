#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(), (v).end()

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> path(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    path[i] = make_pair(a, b);
  }
  vector<int> v(n);
  rep(i, n) {
    v[i] = i + 1;
  }

  int ans = 0;
  do {
    if(v[0] != 1) break; //先頭は1で固定
    bool ok_route = true;
    for(int i = 0; i < n - 1; i++) { //隣あう二つについて
      bool ok = false;
      int before = min(v[i], v[i + 1]);
      int after = max(v[i], v[i + 1]);
      for(int j = 0; j < m; j++) { // pathの検索
        int pa, pb;
        tie(pa, pb) = path[j];
        if(pa == before && pb == after) {
          ok = true;
          break;
        }
      }
      if(ok == false) {
        ok_route = false;
        break; //このvは繋がっていない
      }
    }
    if(ok_route) ans++;

  } while(next_permutation(all(v)));

  cout << ans << endl;
}
