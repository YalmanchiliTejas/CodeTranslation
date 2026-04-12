#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f (ll a, ll m) {
  return (a*a) % m;
}

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  ll ans = 0;
  map<ll, int> ms;
  vector<ll> ans_log, xs;
  ll r = 0; int r_i = 0;
  rep(i,0,m+3) {
    if (ms[x] != 0) {
      r = ans_log[ms[x]-1] - xs[ms[x]-1];
      r_i = ms[x]-1;
      break;
    }
    ans += x;
    ans_log.pb(ans);
    xs.pb(x);
    ms[x] = i+1;
    x = f(x, m);
  }
  if (n <= r_i) {
    cout << ans_log[n-1] << endl;
    return 0;
  }

  ll kr = ans_log[len(ans_log)-1] - r;
  ll c_r = len(ans_log) - r_i;
  n -= r_i;
  ans = (n/c_r) * kr + r;
  n %= c_r;
  if (n == 0) {
    cout << ans << endl;
    return 0;
  }
  ans += ans_log[r_i - 1 + n] - r;
  cout << ans << endl;
  return 0;
}
