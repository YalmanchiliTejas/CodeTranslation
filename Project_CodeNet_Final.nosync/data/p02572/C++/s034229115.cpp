#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mod = 1000000007;
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }

  ll ans = 0;

  rep(i,n) {
    sum -= a[i]%mod;
    if (sum < 0) sum += mod;
    ans += a[i]*sum;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}