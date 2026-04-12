#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

constexpr ll M = 1000000007;

ll modpow(ll n, ll r = M - 2) {
  if (r == 0) return 1;
  auto prev = modpow(n, r / 2);
  auto hoge = (prev * prev) % M;
  return (r % 2 == 0) ? hoge : (hoge * n) % M;
}

ll comb(ll n, ll k) {
  ll pat = 1;
  for (ll i = 0; i < k; i++) {
    pat *= n - i;
    pat %= M;
    pat *= modpow(i + 1ll);
    pat %= M;
  }
  return pat;
}

ll sum_mans(ll n, ll m) {
  ll total = 0;
  auto add = [&total](ll d, ll l) {
    ll dis = d * (d + 1) / 2ll;
    dis %= M;
    dis *= l;
    dis %= M;
    total += dis;
    total %= M;
  };
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      add(i, m);
      add(n - i - 1, m);
      add(j, n);
      add(m - j - 1, n);
    }
  }
  return total;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  ll res = sum_mans(n, m);
  res *= comb(n * m - 2, k - 2);
  res %= M;
  res *= modpow(2);
  res %= M;
  cout << res << endl;
}
