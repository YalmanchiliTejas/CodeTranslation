#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
//const int mod = 1e9 + 7;

struct Combinatorics {
  using int64 = long long;
  int64 mod;
  int64 fact[202020];
  int64 invfact[202020];
  Combinatorics(int64 mod):mod(mod) {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < 202020; ++i) {
      fact[i] = fact[i-1]*i%mod;
      invfact[i] = minv(fact[i]);
    }
  }
  int64 mpow(int64 x, int64 n) const {
    int64 res = 1;
    while(n > 0) {
      if(n&1) res = res*x%mod;
      x = x*x%mod;
      n >>= 1;
    }
    return res;
  }
  int64 minv(int64 x) const {
    return mpow(x, mod-2);
  }
  int64 mfact(int64 x) const {
    return fact[x];
  }
  int64 C(int64 n, int64 r) const {
    if(r < 0 || n < r) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
  }
  int64 P(int64 n, int64 r) const {
    if(r < 0 || n < r) return 0;
    return fact[n]*invfact[n-r]%mod;
  }
};

int N, M;

int dp[3003][3003];
int dfs(int x, int y) {
  if(x < 0 || y < 0) return 0;
  int& res = dp[x][y];
  if(~res) return res;
  if(x == 0 && y == 0) return res = 1;
  if(x < y) return res = 0;
  return res = (dfs(x-1, y-1)+(y+1)*dfs(x-1, y)%M) % M;
}

int way[3003];

int C[3003][3003];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;

  rep(i, 3003) {
    C[i][0] = C[i][i] = 1;
    reps(j, 1, i) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % M;
  }

  memset(dp, -1, sizeof(dp));

  Combinatorics c1(M);
  Combinatorics c2(M-1);
  memset(way, -1, sizeof(way));
  rep(x, N+1) {
    way[x] = 0;
    int b = c1.mpow(2, N-x);
    int p = 1;
    rep(y, N+1) {
      way[x] += dfs(x, y)*p % M;
      way[x] %= M;
      p = p*b % M;
    }
    way[x] *= c1.mpow(2, c2.mpow(2, N-x));
    way[x] %= M;
  }
  int ans = 0;
  rep(i, N+1) {
    if(i&1) ans += M-C[N][i]*way[i]%M;
    else ans += C[N][i]*way[i]%M;
    ans %= M;
  }
  cout << ans << endl;

  return 0;
}
