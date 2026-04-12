#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) {
    cin >> a[i];
  }
  vector<ll> sum(n, 0);
  sum[0] = a[0];
  for (ll i = 1; i < n; i++) {
    sum[i] = (sum[i - 1] + a[i]) % MOD;
  }
  ll ans = 0;

  for (ll i = 0; i < n; i++) {
    ans += (a[i] * ((sum[n - 1] - sum[i]+MOD) % MOD)) % MOD;
    ans %= MOD;
  }

  cout << ans % MOD << endl;
  return 0;
}
