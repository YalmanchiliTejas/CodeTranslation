#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  multiset<ll> s;
  s.insert(a[0]);
  for (int i = 1; i < n; i++) {
    auto it = s.lower_bound(a[i]);
    if (it == s.begin()) {
      s.insert(a[i]);
    } else {
      it--;
      s.erase(it);
      s.insert(a[i]);
    }
  }
  cout << s.size() << endl;
  return 0;
}
