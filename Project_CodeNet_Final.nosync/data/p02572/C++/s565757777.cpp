//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


void solve() {
  int n;
  cin >> n;
  ll a[n], sum = 0, pre[n+1];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum = (sum + a[i]) % MOD;
    pre[i+1] = sum;
  }
  pre[0] = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += a[i] * pre[i] % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  //cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  