#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int a[100010];
  rep(i, n) cin >> a[i];

  sort(a, a+n);

  vector <int> l;
  ll ans = 0;

  if (n%2 == 0) {
    l = {1, -1};
    rep(i, (n-2)/2) l.push_back(2);
    rep(i, (n-2)/2) l.push_back(-2);
    sort(l.begin(), l.end());
    rep(i, n) ans += a[i] * l[i];
  } else {
    l = {1, 1};
    rep(i, n/2) l.push_back(-2);
    rep(i, n/2-1) l.push_back(2);
    sort(l.begin(), l.end());
    rep(i, n) ans += a[i] * l[i];

    ll cnt = 0;
    l = {-1, -1};
    rep(i, n/2) l.push_back(2);
    rep(i, n/2-1) l.push_back(-2);
    sort(l.begin(), l.end());
    rep(i, n) cnt += a[i] * l[i];

    ans = max(ans, cnt);
  }

  cout << ans << endl;
}