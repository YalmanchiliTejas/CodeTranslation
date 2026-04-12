#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int n;
vi a;

void input() {
  cin >> n;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void solve() {
  vector<ll> s(n);

  s[0] = a[0];

  for (int i = 1; i < n; ++i)
    s[i] = s[i - 1] + a[i];

  int ans = 0;
  
  for (int i = 0; i < n - 1; ++i) {
    ll sum = s.back() - s[i];

    sum %= MOD;

    int tmp = (a[i] * sum) % MOD;

    ans = (ans + tmp) % MOD;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
