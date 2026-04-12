#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll bread[51], patty[51];

int c = 0, d = 0;

ll rec(ll n, ll x) {
  if (n == 0)
    return 1;
  if (x == 1)
    return 0;

  ll mid = (bread[n] + patty[n]) / 2 + 1;
  ll ans = 0;
  if (x > mid) {
    ans += patty[n - 1] + 1;
    x -= bread[n - 1] + patty[n - 1] + 1;
    c++;
  } else if (x == mid)
    return patty[n - 1] + 1;
  d++;
  ans += rec(n - 1, x - 1);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, x;
  cin >> n >> x;
  bread[0] = 0, patty[0] = 1;
  rep(i, 1, 51) {
    bread[i] = bread[i - 1] * 2 + 2;
    patty[i] = patty[i - 1] * 2 + 1;
  }

  if (n >= x) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = rec(n, x);
  cout << ans << endl;
}
