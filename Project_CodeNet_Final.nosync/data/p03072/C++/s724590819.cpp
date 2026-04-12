#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO;
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int ans = 0;
  int mx = 0;
  for (auto x : v) {
    ans += (mx <= x);
    mx = max(mx, x);
  }

  cout << ans << endl;

  return 0;
}
