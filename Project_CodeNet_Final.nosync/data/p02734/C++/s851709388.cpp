#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

const int M = 998244353;
void add(ll &x, ll y) { x = (x+y)%M; }

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  vector<ll> q(s+1);
  ll ans = 0;
  rep(i, n) {
    add(q[0], 1);
    // q[0] = (q[0] + 1)%M;
    //-----
    vector<ll> q2(s+1);
    rep(j, s+1) {
      add(q2[j], q[j]);
      // q2[j] = (q2[j]+q[j])%M;
      // if (j + a[i] <= s) q2[j+a[i]] = (q2[j+a[i]]+q[j])%M;
      if (j + a[i] <= s) add(q2[j+a[i]], q[j]);
    }
    q = q2;
    //-----
    add(ans, q[s]);
    // ans = (ans + q[s])%M;
  }
  cout << ans << endl;
}