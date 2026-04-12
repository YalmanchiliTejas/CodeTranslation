#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(bool head, vector<ll>& a) {
  int n = a.size();
  vector<ll> x;
  ll m = head ? 1 : -1;
  for (int i = 0; i < n; ++i) {
    x.push_back(m * (i == 0 || i == n - 1 ? 1 : 2));
    m *= -1;
  }
  sort(x.rbegin(), x.rend());
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * x[i];
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll ans = max(f(true, a), f(false, a));

  cout << ans << endl;
}
