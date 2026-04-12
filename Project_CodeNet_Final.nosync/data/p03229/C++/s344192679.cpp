#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, ans = 0;
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  rep(x, 2) {
    ll i = 0, now = 0;
    for(; i < n / 2; i++) b[2 * i + 1] = a[i];
    if(n % 2) {
      b[n - 1] = a[i];
      i++;
    }
    for(ll j = 0; i + j < n; j++) b[2 * j] = a[i + j];
    rep(k, n - 1) now += abs(b[k] - b[k + 1]);
    ans = max(ans, now);
    if(x == 0) reverse(all(a));
  }
  cout << ans << endl;
}