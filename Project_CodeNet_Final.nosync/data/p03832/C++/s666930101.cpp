#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define PB(a) push_back(a)
#define EB(...) emplace_back(__VA_ARGS__)
#define MP(a, b) make_pair(a, b)
#define MT(...) make_tuple(__VA_ARGS__)
#define Bit(n) (1LL << (n))
using namespace std;
using pii = pair<int, int>;
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const int INF = 1LL << 30;
const double EPS = 1e-10;

const int MAX_N = 2010;
int ext_gcd(int a,int b,int& x,int& y) {
  if(b==0){
    x=1;y=0;return a;
  }
  int q=a/b;
  int g=ext_gcd(b,a-q*b,x,y);
  int z=x-q*y;
  x=y;y=z;
  return g;
}
int inv_mod(int a,int m) {
  int x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}
int fac[MAX_N],finv[MAX_N],inv[MAX_N];
void make(){
  fac[0]=1%MOD;
  for(int i=1;i<MAX_N;i++)fac[i]=fac[i-1]*i%MOD;
  finv[MAX_N-1]=inv_mod(fac[MAX_N-1],MOD);
  for(int i=MAX_N-2;i>=0;i--)finv[i]=finv[i+1]*(i+1)%MOD;
  for(int i=1;i<MAX_N;i++)inv[i]=finv[i-1]%MOD;
}

int pow_mod(int x, int n, int m) {
  int r = 1;
  while (n) {
    if (n & 1) r = r*x%m;
    x = x*x%m;
    n >>= 1;
  }
  return r;
}

int N, A, B, C, D;
int dp[1010];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  make();
  cin >> N >> A >> B >> C >> D;
  dp[0] = 1;
  REP(i, N) {
    int p = i+1;
    if (A <= p && p <= B) {
      REPR(j, N) {
        FOR(k, C, D+1) {
          if (j-k*p < 0) break;
          int tmp = fac[j] * finv[j-k*p] % MOD * finv[k] % MOD * inv_mod(pow_mod(fac[p], k, MOD), MOD) % MOD;
          (dp[j] += dp[j-k*p] * tmp % MOD) %= MOD;
        }
      }
    }
  }
  cout << dp[N] << endl;

  return 0;
}