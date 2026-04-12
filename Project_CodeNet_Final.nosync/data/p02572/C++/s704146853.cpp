#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using namespace boost::multiprecision;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n;
  cpp_int ans = 0;
  cin >> n;
  vector<cpp_int> a(n), s(n + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) s[i + 1] = s[i] + a[i];
  rep(i, n - 1) {
    cpp_int t = a[i] * (s[n] - s[i + 1]);
    ans = ans + t;
  }
  ans = ans % MOD;

  cout << ans << endl;
  return 0;
}