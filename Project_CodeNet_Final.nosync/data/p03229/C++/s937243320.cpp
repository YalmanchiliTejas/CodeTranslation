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
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  ll ans = 0;
  if (a.size()%2 == 0) {
    for (ll i = 0; i < (n-2)/2; ++i) {
      ans += a[i] * -2;
    }
    for (ll i = 0; i < (n-2)/2; ++i) {
      ans += a[n-i-1] * 2;
    }
    ans += a[n/2-1] * -1;
    ans += a[n/2];
  } else {
    vector<ll> p1 = {-1, -1};
    vector<ll> p2 = {1, 1};
    for (ll i = 0; i < (n-2+1)/2; ++i) {
      p1.push_back(2);
      p2.push_back(-2);
    }
    for (ll i = 0; i < (n-2)/2; ++i) {
      p1.push_back(-2);
      p2.push_back(2);
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    ll sum1 = 0, sum2 = 0;
    for (ll i = 0; i < n; ++i) {
      sum1 += a[i] * p1[i];
      sum2 += a[i] * p2[i];
    }
    ans = max(sum1, sum2);
  }

  cout << ans << endl;

  
  return 0;
}
