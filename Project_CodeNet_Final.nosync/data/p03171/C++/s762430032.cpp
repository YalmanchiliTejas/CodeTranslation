#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using ii = pair <int, int>;

#define int long long
#define FOR(a, b, c) for(int a = b, _c = c; a <= _c; ++a)
#define FORD(a, b, c) for(int a = b, _c = c; a >= _c; --a)
#define REP(a, b, c) for(int a = b, _ = c; a < _; ++a)
#define ALL(a, b) for(auto &a : b)
#define pb push_back
#define mp make_pair
#define all(a) begin(a), end(a)
#define reset(f, x) memset(f, x, sizeof(f))
#define fi first
#define se second
#define bit(x, i) (x >> (i - 1) & 1ll)
#define onbit(x, i) (x | (1ll << (i - 1)))
#define offbit(x, i) (x & ~(1ll << (i - 1)))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll

template <class T> void Max(T &x, T y) { x = (x > y) ? x : y;}

const int N = 3005;
int n;
ll s, a[N], f[N][N];

ll F(int l, int r) {
  if(l > r) return 0;
  if(f[l][r] != -1) return f[l][r];
  ll ans;
  if((l + r) % 2 != n % 2) ans = max(F(l + 1, r) + a[l], F(l, r - 1) + a[r]);
  else ans = min(F(l + 1, r) - a[l], F(l, r - 1) - a[r]);
  return f[l][r] = ans;
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  FOR(i, 1, n) cin >> a[i], s += a[i];
  reset(f, -1);
  cout << F(1, n) << '\n';
}
