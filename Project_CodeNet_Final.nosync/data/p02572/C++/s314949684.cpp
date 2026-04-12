#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int MOD = 1e9 + 7;

void add(int &x, int y) {
  x += y;
  if (x < 0) x += MOD;
  if (x >= MOD) x-= MOD;
}
int mul(int x, int y) {
  return (1LL * x * y) % MOD;
}

void solve() {
  int n; cin >> n;
  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    add(ans, mul(sum, v));
    add(sum, v);
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
