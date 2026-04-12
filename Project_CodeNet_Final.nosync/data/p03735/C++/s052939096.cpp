#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;
int n, le, ri;
pair <int, int> a[N];
multiset <int> s;

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  le = 1e9;
  for(int i = 1; i <= n; ++i) {
    int u, v;
    cin >> u >> v;
    if(u > v) swap(u, v);
    a[i] = make_pair(u, v);
    le = min(le, u);
    ri = max(ri, v);
    s.insert(u);
  }
  int mi = 1e9, ma = 0;
  for(int i = 1; i <= n; ++i) {
    ma = max(ma, a[i].first);
    mi = min(mi, a[i].second);
  }
  int ans = (ma - le) * (ri - mi);
  sort(a + 1, a + n + 1);
  ans = min(ans, (*s.rbegin() - *s.begin()) * (ri - le));
  for(int i = 1; i <= n; ++i) {
    s.erase(s.find(a[i].first));
    s.insert(a[i].second);
     ans = min(ans, (*s.rbegin() - *s.begin()) * (ri - le));
  }
  cout << ans;
}
