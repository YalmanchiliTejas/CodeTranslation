#include <bits/stdc++.h>
using namespace std;

#define each(i, c) for (auto& i : c)
#define mkp(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pll;
const ll MOD = 1e9+7;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << ": " << p.second << ")"; return os; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ", "; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; each (i, m) os << i << ", "; os << "}"; return os; }

int main() {
  ll n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << n*n << endl;
    return 0;
  }

  ll ans = 0;
  for (ll i = k+1; i <= n; ++i) {
    ll mul = i-k;
    ll sum = mul * ((n/i)+1);

    ll l = i*(n/i) + k;
    ll r = i*(n/i) + (i-1);
    if (n < l) {
      sum -= (r-l)+1;
    } else if (l <= n && n < r) {
      sum -= (r-n);
    }
    ans += sum;
  }

  cout << ans << endl;

  return 0;
}
