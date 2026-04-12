#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> v;
  multiset<int> s;
  map<int, int> id;
  rep(i, n) {
    auto it = s.lower_bound(a[i]);
    if (it == s.begin()) {
      id[a[i]] = v.size();
      v.push_back(vector<int>{a[i]});
      s.insert(a[i]);
    } else {
      --it;
      id[a[i]] = id[*it];
      v[id[a[i]]].push_back(a[i]);
      s.erase(s.find(*it));
      s.insert(a[i]);
    }
  }

  int ans = v.size();
  cout << ans << endl;

  return 0;
}
