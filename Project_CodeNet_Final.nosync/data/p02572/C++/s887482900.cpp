#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int, int>;

ll mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> aSum(n);
  for (int i = n-1; i > 0; --i) {
    aSum[i-1] = aSum[i] + a[i];
    aSum[i-1] %= mod;
  }
  ll ans = 0;
  rep(i,n) {
    ans += (aSum[i] * a[i]) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}