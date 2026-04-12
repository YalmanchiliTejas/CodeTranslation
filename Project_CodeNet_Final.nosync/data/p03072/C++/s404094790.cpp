#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,x; cin >> n;
  int lmax = 0, ans = 0;
  for(int i = 0; i < n; ++i) {
    cin >> x;
    ans += (x>=lmax) ? 1 : 0;
    lmax = max(lmax,x);
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}