#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                         \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll A, ll B, ll C, ll X, ll Y) {
  ll result = 0;

  if (A + B >= 2 * C) {
    if (X >= Y) {
      if (A <= 2 * C) {
        result += (2 * C) * Y;
        result += A * (X - Y);
      } else {
        result += 2 * C * X;
      }
    } else {
      if (B <= 2 * C) {
        result += (2 * C) * X;
        result += B * (Y - X);
      } else {
        result += 2 * C * Y;
      }
    }
  } else {
    result += A * X + B * Y;
  }

  cout << result << endl;
}

int main() {
  ll A;
  scanf("%lld", &A);
  ll B;
  scanf("%lld", &B);
  ll C;
  scanf("%lld", &C);
  ll X;
  scanf("%lld", &X);
  ll Y;
  scanf("%lld", &Y);
  solve(A, B, C, X, Y);
  return 0;
}
