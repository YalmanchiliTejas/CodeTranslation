#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

const int MOD = 1e9 + 7;

using ll = long long;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vi v(n), p(n + 1);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  p[n] = 0;
  for (int i = n - 1; i >= 0; i--)
    p[i] = (0LL + p[i + 1] + v[i]) % MOD;

  ll ans = 0;
  for (int i = 0; i < n - 1; i++)
    ans = (ans + 1LL * v[i] * p[i + 1]) % MOD;

  cout << ans << endl;

  return 0;
}
