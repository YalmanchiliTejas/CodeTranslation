#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(vector<ll> a, ll r) {
  vector<int> c(r + 1);
  int n = a.size();
  for (int i = 0; i <= r; i++)
    c[i] = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j * a[i] <= r; j++) {
      c[j * a[i]] = min(c[j * a[i]], i);
    }
  }
  ll ret = 0;
  for (int i = 0; i <= r; i++) {
    if (c[i] == n) {
      if (n % 2 == 0)
        ret++;
    } else {
      if (c[i] % 2 == 0)
        ret++;
    }
  }
  return ret;
}

int main() {
  while (true) {
    ll n, l, r;
    cin >> n >> l >> r;
    if (n == 0)
      break;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << f(a, r) - f(a, l - 1) << endl;
  }
  return 0;
}
