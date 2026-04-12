#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
// using namespace atcoder;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000000000000ll
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
//#define __DEBUG__
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
  int n;
  cin >> n;
  vector<ll> h(n);
  REP(i, n) cin >> h[i];
  int ans = 0;
  REP(i, n) {
    bool f = true;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) f = false;
    }
    if (f) ans++;
  }
  cout << ans << endl;
  return 0;
}
