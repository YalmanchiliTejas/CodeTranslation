#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, n) cin >> a[i], sum += a[i];
  ll res = 0;
  for (int i = 0; i < n; i++) {
    sum -= a[i];
    ll tmp = a[i] * (sum % MOD);
    res += tmp % MOD;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}