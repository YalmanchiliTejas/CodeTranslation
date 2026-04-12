#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc()) 
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const int MOD = 998244353, G = 5;
inline void Add(int &x,int y) {
  x = x + y >= MOD ? x + y - MOD : x + y;
}
inline void Sub(int &x,int y) {
  x = x - y < 0 ? x - y + MOD : x - y;
}
int power(int a,int b) {
  int ret = 1;
  while (b) {
    if (b&1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

const int N = 200010;
int rev[N];
void prework(int n) {
  rev[0] = 0;
  rep (i, 1, n-1)
    if (i&1) rev[i] = rev[i^1] | (n >> 1);
    else rev[i] = rev[i >> 1] >> 1;
}
void dft(int *a,int n,int sgn) {
  rep (i, 0, n-1) if (i < rev[i])
    swap(a[i], a[rev[i]]);
  int w, wp, u, v;
  for (int s = 2; s <= n; s <<= 1) {
    wp = power(G, (MOD - 1) / s);
    if (sgn) wp = power(wp, MOD - 2);
    for (int k = 0; k < n; k += s) {
      w = 1;
      for (int j = 0; j < (s >> 1); ++ j) {
	u = a[k + j];
	v = 1ll * a[k + j + (s >> 1)] * w % MOD;
	a[k + j] = (u + v >= MOD ? u + v - MOD : u + v);
	a[k + j + (s >> 1)] = (u - v < 0 ? u - v + MOD : u - v);
	w = 1ll * w * wp % MOD;
      }
    }
  }
  if (sgn) {
    w = power(n, MOD - 2);
    rep (i, 0, n-1) a[i] = 1ll * a[i] * w % MOD;
  }
}

const int M = 210;
int n, m;
int dp[M][N];
int jc[N], ijc[N];
void prework_comb(int sz) {
  jc[0] = 1;
  rep (i, 1, sz) jc[i] = 1ll * jc[i-1] * i % MOD;
  ijc[sz] = power(jc[sz], MOD - 2);
  rrp (i, sz-1, 0) ijc[i] = 1ll * ijc[i+1] * (i+1) % MOD;
}
int comb(int a,int b) {
  if (a < b || b < 0) return 0;
  return 1ll * jc[a] * ijc[b] % MOD * ijc[a-b] % MOD;
}
int ta[N], tb[N];
int main() {
  read(n), read(m);
  prework_comb(n + 2);
  dp[0][0] = 1;
  rep (i, 1, m) {
    rep (j, 0, n) {
      dp[i][j] = dp[i-1][j];
      Add(dp[i][j], 1ll * j * (j + 1) / 2 % MOD * dp[i-1][j] % MOD);
    }
    int l = 1;
    while (l < 2 * n + 1) l <<= 1;
    prework(l);
    rep (i, 0, l-1) ta[i] = tb[i] = 0;
    rep (k, 1, n) tb[k] = ijc[k + 2];
    rep (j, 0, n) ta[j] = 1ll * dp[i-1][j] * ijc[j] % MOD;
    dft(tb, l, 0), dft(ta, l, 0);
    rep (i, 0, l-1) ta[i] = 1ll * ta[i] * tb[i] % MOD;
    dft(ta, l, 1);
    rep (j, 0, n) Add(dp[i][j], 1ll * ta[j] * jc[j+2] % MOD);
    // rep (j, 0, n) {
    //   rep (k, 1, j) {
    // 	Add(dp[i][j], 1ll * dp[i-1][j - k] * comb(j + 2, k + 2) % MOD);
    //   }
    // }
    // rep (j, 0, n) cerr << dp[i][j] << ' ';
    // cerr << endl;
  }
  int ans = 0;
  rep (i, 0, n) Add(ans, 1ll * comb(n, i) * dp[m][i] % MOD);
  printf("%d\n", ans);
  return 0;
}
