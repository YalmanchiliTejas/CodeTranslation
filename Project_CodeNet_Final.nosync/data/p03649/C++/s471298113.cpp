#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll ans = 0;
  while (1) {
    ll cnt = 0;
    REP(i,n) {
      cnt += a[i]/n;
    }
    if (cnt == 0) break;
    REP(i,n) {
      ll k = a[i]/n;
      a[i] %= n;
      a[i] += cnt - k;
    }
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}
