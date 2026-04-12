#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<int> ans;
  ans.push_back(a[0]);
  rep(i, 1, n) {
    auto idx = lower_bound(ans.rbegin(), ans.rend(), a[i]);
    auto xxx = ans.size() - 1 - (idx - ans.rbegin());
    if (idx != ans.rend()) {
      if (xxx + 1 == ans.size()) {
        ans.push_back(a[i]);
      } else {
        ans[xxx + 1] = a[i]; 
      }
    } else if (idx == ans.rend()) {
      ans[0] = a[i];
    }
  }

  cout << ans.size() << endl;
}
