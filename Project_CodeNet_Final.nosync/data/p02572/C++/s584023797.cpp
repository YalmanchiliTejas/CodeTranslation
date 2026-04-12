#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005];

// ------------------------------------
// 1 is true
// 0 is false
// ------------------------------------

ll binexp(ll x, ll n, ll m) {
  x %= m;
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const ll k = 1000000007;
  ll sumai = 0, sumaisq = 0, minvtwo = binexp(2, (k - 2), k);
  for (int i = 0; i < n; i++) {
    sumai += a[i] % k;
    sumaisq += ((a[i] % k) * (a[i] % k)) % k;
    sumai = sumai % k;
    sumaisq = sumaisq % k;
  }

  cout << (minvtwo * ((sumai * sumai - sumaisq) % k)) % k << endl;
}
