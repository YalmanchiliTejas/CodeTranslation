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
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define bit(x, i) (x >> (i - 1) & 1ll)
#define onbit(x, i) (x | (1ll << (i - 1)))
#define offbit(x, i) (x & ~(1ll << (i - 1)))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll

template <class T> void Max(T &x, T y) { x = (x > y) ? x : y;}

const int N = 1e4 + 5;
const ll mod = 1e9 + 7;
string k;
int a[N], d;
ll f[N][105][2];

void add(ll &x, ll y) {
  x = (x + y) % mod;
}

ll F(int i, int r, int o) {
  if(i > sz(k)) return !r;
  if(f[i][r][o] != -1) return f[i][r][o];
  ll ans = 0;
  FOR(j, 0, (o ? 9 : a[i])) add(ans, F(i + 1, (r + j) % d, j < a[i] || o));
  return f[i][r][o] = ans;
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> k >> d;
  reset(f, -1);
  REP(i, 0, sz(k)) a[i + 1] = k[i] - '0';
  cout << (F(1, 0, 0) - 1 + mod) % mod;
}
