#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

ll n;
vl a;

ll sum() {
  ll res = 0;
  rep(i, n) res += a[i] / n;
  return res;
}

int main() {
  cin >> n;
  a = vl(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll s = sum();
  while(s > 0) {
    ans += s;
    rep(i, n) a[i] += s - a[i] / n - a[i] / n * n;
    s = sum();
  }
  cout << ans << endl;
}