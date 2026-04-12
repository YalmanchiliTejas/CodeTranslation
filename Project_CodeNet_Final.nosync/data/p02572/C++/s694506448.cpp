#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  int n; cin >> n;
  vector <ll> a(n);
  for(auto &x : a) cin >> x;
  reverse(a.begin(), a.end());
  ll sum = 0;
  ll ans = 0;
  for(int i = 0; i < n - 1; i++) {
    sum = (sum + a[i]) % MOD;
    ans = (ans + sum * a[i + 1] % MOD) % MOD;
  }
  cout << ans << '\n';
}
