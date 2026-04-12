#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#define int long long
#define FOR(a, b, c) for(int a = b, _c = c; a <= _c; ++a)
#define ROF(a, b, c) for(int a = b, _c = c; a >= _c; --a)
#define REP(a, b, c) for(int a = b, _c = c; a < _c; ++a)
#define VEC(a, b) for(auto &a : b)
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define sz(x) (int)(x.size())
#define bit(x, i) (x >> (i - 1) & 1ll)
#define onbit(x, i) (x | (1ll << (i - 1)))
#define offbit(x, i) (x & ~(1ll << (i - 1)))

template <class T> void Max(T &x, T y) { x = (x > y) ? x : y;}
template <class T> void Min(T &x, T y) { x = (x < y) ? x : y;}

#define debug(x) cerr << #x << '=' << x << '\n'
#define debugn(a, n) FOR(i, 1, n) cerr << a[i] << ' '
#define debugv(a) VEC(v, a) cerr << v << ' '

const int N = 2e5 + 5;
const int inf = 1e18;
int n, a[N];
int f[N][3][3];

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 0, n) FOR(j, 0, 2) FOR(k, 0, 1) f[i][j][k] = -inf;
  f[0][0][0] = 0;
  for(int i = 1; i <= n;  i += 2) {
    int j = (i + 1) / 2;
    f[j][0][1] = max({ f[j - 1][0][0], f[j - 1][2][0], f[j - 1][1][0]});
    f[j][1][0] = max(f[j - 1][0][0], f[j - 1][1][0]) + a[i];
    f[j][2][0] = max({ f[j - 1][0][0], f[j - 1][1][0], f[j - 1][2][0]}) + a[i + 1];
    f[j][1][1] = max({ f[j - 1][0][1], f[j - 1][1][1]}) + a[i];
    f[j][2][1] = max({ f[j - 1][0][1], f[j - 1][1][1], f[j - 1][2][1]}) + a[i + 1];
  }
  int ans = max(f[n / 2][1][0], f[n / 2][2][0]);
  if(n % 2 == 1) ans = max(ans, max(f[n / 2][0][1], f[n / 2][1][1]) + a[n]);
  cout << ans;
}
