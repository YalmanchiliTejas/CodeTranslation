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

ll a[51], p[51];

ll f(int n, ll x) {
  if (n == 0)
    return x <= 0 ? 0 : 1;
  if (x <= a[n - 1] + 1LL)
    return f(n - 1, x - 1LL);
  if (x == 2 + a[n - 1])
    return p[n - 1] + 1;
  if (x <= 2 * a[n - 1] + 2)
    return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
  return 2 * p[n - 1] + 1;
}

ll N, X;
int main() {
  cin >> N >> X;
  a[0] = 1;
  p[0] = 1;
  rep2(i, 1, N) {
    a[i] = 2 * a[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }
  cout << f(N, X) << endl;
  return 0;
}
