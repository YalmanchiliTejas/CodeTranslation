#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

ll N, X, M;
int main() {
  cin >> N >> X >> M;
  vi a;
  vi id(M, -1);
  int len = 0;
  ll tot = 0;
  while (id[X] == -1) {
    a.pb(X);
    id[X] = len;
    len++;
    tot += X;
    X = (X * X) % M;
  }
  ll sum = 0;
  for (int i = id[X]; i < len; ++i) {
    sum += a[i];
  }
  int c = len - id[X];
  ll ans = 0;
  if (len < N) {
    ans += tot;
    N -= len;
    ans += sum * (N / c);
    N %= c;
    rep(i, N) ans += a[id[X] + i];
  } else {
    rep(i, N) ans += a[i];
  }
  printf("%lld\n", ans);
  return 0;
}
