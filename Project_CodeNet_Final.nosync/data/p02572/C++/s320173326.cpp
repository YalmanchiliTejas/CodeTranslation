#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a (n);
  vector < ll > suf (n);
  for (auto &i : a) cin >> i;
  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) suf[i] = (a[i] + suf[i + 1]) % mod;

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += a[i] * suf[i + 1];
    ans %= mod;
  }

  cout << ans << '\n';
}
