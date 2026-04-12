#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n; cin >> n;
  vector<ii> a(n);
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].fi;
    a[i].sc = i;
  }
  sort(all(a));
  int l = n / 2 - 1;
  for (int i = 0; i < n; i++) {
    if (i <= l) {
      res[a[i].sc] = a[l + 1].fi;
    }
    else {
      res[a[i].sc] = a[l].fi;
    }
  }
  for (auto &i : res) cout << i << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
