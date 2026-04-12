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

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll sum = 0;
  vl d(n, 0);
  rep(i, n) {
    d[i] = a[i] / n;
    sum += d[i];
  }
  while(sum) {
    ans += sum;
    rep(i, n) {
      a[i] -= d[i] * n;
      a[i] += sum - d[i];
    }
    sum = 0;
    rep(i, n) {
      d[i] = a[i] / n;
      sum += d[i];
    }
  }
  cout << ans << endl;
}