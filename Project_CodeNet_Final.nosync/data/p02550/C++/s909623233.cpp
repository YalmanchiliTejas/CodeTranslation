#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> a;
  vector<ll> ord(m, -1);
  ll tmp = x;
  ll si = 0;
  ll t = 0;
  a.push_back(tmp);
  ord[x] = 0;
  for (int i = 0; i < n; i++) {
    tmp = tmp * tmp % m;
    if (ord[tmp] != -1) {
      si = ord[tmp];
      t = i + 1 - ord[tmp];
      break;
    }
    ord[tmp] = i + 1;
    a.push_back(tmp);
  }
  vector<ll> ruiseki(a.size() + 1, 0);
  rep(i, a.size()) { ruiseki[i + 1] = ruiseki[i] + a[i]; }
  ll ans = 0;
  if (n <= a.size()) {
    ans = ruiseki[n];
    cout << ans << endl;
    return 0;
  }
  ll cnt = (n - si) / t;
  ll id = (n - si) % t;
  ans = (ruiseki[t + si] - ruiseki[si]) * cnt + ruiseki[si] +
        ruiseki[id + si] - ruiseki[si];
  cout << ans << endl;
  // rep(i, a.size()) cout << a[i] << ", ";
  // cout << endl;
  // rep(i, a.size() + 1) cout << ruiseki[i] << ", ";
  // cout << endl;
  // cout << si << endl;
  // cout << t << endl;
  return 0;
}