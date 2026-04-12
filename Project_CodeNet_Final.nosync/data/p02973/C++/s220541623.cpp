#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, j, n) for (int i = (j); i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& u : a) cin >> u;
  vector<int> b;
  b.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    int x = lower_bound(begin(b), end(b), a[i]) - begin(b);
    if (x == 0)
      b.insert(b.begin(), a[i]);
    else
      b[x - 1] = a[i];
  }
  cout << b.size() << endl;
}