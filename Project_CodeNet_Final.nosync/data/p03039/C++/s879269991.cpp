#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

// 逆元 | a と mod は互いに素
int inv_mod(int a, int m = MOD) {
  int b = m, x = 1, y = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b);
    swap(x -= t * y, y);
  }
  x %= m;
  if (x < 0) x += m;
  return x;
}

// 逆元(配列) | 1...n-1 は mod と互いに素, n <= mod
int fac[200010], invfac[200010], inv[200010];
void init(int n, int mod = MOD) {
  fac[0] = 1;
  for (int i = 1; i < n; i++) fac[i] = fac[i-1]*i%mod;
  invfac[n-1] = inv_mod(fac[n-1]);
  for (int i = n-2; i >= 0; i--) invfac[i] = invfac[i+1]*(i+1)%mod;
  for (int i = 1; i < n; i++) inv[i] = invfac[i]*fac[i-1]%mod;
}

// 二項係数 | n,k < mod, mod は素数
int nCk(int n, int k, int mod = MOD) {
  if (!(0 <= k && k <= n)) return 0;
  return fac[n] * invfac[k] % mod * invfac[n-k] % mod;
}

int calc(int n, int m, int k) {
  int res = 0;
  REP(d,n) (res += d*(n-d)%MOD) %= MOD;
  (res *= m*m%MOD) %= MOD;
  (res *= nCk(n*m-2,k-2)) %= MOD;
  return res;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  init(200010);
  int N,M,K;
  cin >> N >> M >> K;
  cout << (calc(N,M,K) + calc(M,N,K)) % MOD << endl; 

  return 0;
}