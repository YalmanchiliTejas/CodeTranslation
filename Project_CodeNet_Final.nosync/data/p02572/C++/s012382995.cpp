#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef map<ll, ll> M;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((ll)(x).size())

int main() {
  ll n, mod = 1000000000 + 7, result = 0;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  ll tmp = 0;
  REP(i, n-1) tmp += a[i];
  for (ll i = n-1; i > 0; i--) {
    result += ((tmp % mod) * (a[i] % mod)) % mod;
    tmp -= a[i-1];
  }
  cout << result % mod << endl;
  return 0;
}
