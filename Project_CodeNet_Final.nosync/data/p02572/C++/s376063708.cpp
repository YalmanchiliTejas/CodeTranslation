#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll n, ans;

int main() {
  cin >> n;
  vector<ll> a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vector<ll> s(n, 0);
  for (int i = n-2; i >= 0; i--) {
    s[i] = s[i+1] + a[i+1];
    s[i] %= 1000000007;
  }
  ans = 0;
  rep (i, n) {
    ans += (a[i] * s[i]) % 1000000007;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
