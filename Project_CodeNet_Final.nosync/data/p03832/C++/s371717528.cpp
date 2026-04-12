//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
const int INF = (1LL<<30);
const ll LLINF = (1LL<<60);
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;
//#define int ll

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

ll dp[1010][1010], comb[1010][1010], fact[1010], ifact[1010];

//二分累乗法 xのe乗
ll binpow(ll x, ll e) {
  ll a = 1, p = x;
  while(e > 0) {
    if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}
    else {a = (a*p) % MOD; e--;}
  }
  return a % MOD;
}

void pascalTriangle(int n) {
  REP(i, n) {
    comb[i][0] = 1;
    comb[i][i] = 1;
    FOR(j, 1, i) comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
  }
}

void initFact(int n) {
  fact[0] = fact[1] = 1;
  ifact[1] = 1;
  FOR(i, 2, n) {
    fact[i] = (fact[i-1] * i) % MOD;
    ifact[i] = binpow(fact[i], MOD-2);
  }
}

ll P(ll n, int r) {
  return fact[n]*binpow(fact[n-r], MOD-2)%MOD;
}

signed main(void)
{
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  fact[0] = 1;
  for(int i = 1; i <= n; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }

  dp[a-1][0] = 1;
  for(int i = a; i <= b; i++) {
    for(int j = 0; j <= n; j++) dp[i][j] = dp[i-1][j];
    for(int k = c; k <= d; k++) {
      for(int j = i * k; j <= n; j++) {
	      dp[i][j] = (dp[i][j] + (dp[i-1][j-i*k] * P(j,i*k) % MOD) * binpow(binpow(fact[i],k) * fact[k] % MOD, MOD-2) % MOD) % MOD;
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}
