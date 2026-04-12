#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, tans = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  deque<ll> dq;
  rep(i, n) dq.push_back(a[i]);

  for (int i = 0; i < 2; ++i) {
    ll r = dq.front();
    ll l = r;
    dq.pop_front();
    ans = 0;
    while (dq.size()) {
      ll b = dq.back();
      ll f = dq.front();
      ll mx = max({abs(r - b), abs(r - f), abs(l - b), abs(l - f)});
      ans += mx;
      if (mx == abs(r - b))
        r = b, dq.pop_back();
      else if (mx == abs(l - b))
        l = b, dq.pop_back();
      else if (mx == abs(r - f))
        r = f, dq.pop_front();
      else if (mx == abs(l - f))
        l = f, dq.pop_front();
    }
    rep(i, n) dq.push_front(a[i]);
    tans = max(tans, ans);
  }

  cout << tans << endl;
  return 0;
}
