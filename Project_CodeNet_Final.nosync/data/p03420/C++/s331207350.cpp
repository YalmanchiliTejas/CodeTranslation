#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  int k;
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }

  ll ans = 0;
  rep(b, k + 1, n + 1) {
    ans += (n / b) * (b - k);
    ans += max(0LL, (n % b) - (k - 1));
  }

  cout << ans << endl;
}
