#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;
ll m = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  ll sum = 0;
  ll ans = 0;
  rep(i, n) sum += a[i];
  rep(i, n-1) {
    sum -= a[i];
    ans += ((a[i] % m) * (sum % m));
    ans %= m;
  }
  cout << ans << endl;
  return 0;
}