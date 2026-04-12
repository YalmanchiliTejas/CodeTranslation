#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

/* exchange */
#define chmin(a, b) (a) = min((ll)(a), (ll)(b))
#define chmax(a, b) (a) = max((ll)(a), (ll)(b))

/* output */
#define I(x) cin >> x;
#define D(x) cerr << (x) << " ";
#define BR cerr << "\n";
#define P(x) cout << (x) << endl;
#define FIX cout << fixed << setprecision(10);

/* const */
const int ARRAY = 200005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N = 0, M, K;
ll ret = 0;

ll fact[ARRAY];
ll inv_fact[ARRAY];
ll inv[ARRAY];

void combiInit() {
  fact[0] = fact[1] = 1;
  inv_fact[0] = inv_fact[1] = 1;
  inv[1] = 1;
  FOR(i, 2, ARRAY) {
    fact[i] = fact[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    inv_fact[i] = inv_fact[i-1] * inv[i] % MOD;
  }
}

ll combi(ll n, ll r) {
  if (n < r) return 0;
  if (n < 0 || r < 0) return 0;
  return fact[n] * (inv_fact[r] * inv_fact[n-r] % MOD) % MOD;
}

int main(void){
  
  I(N);
  I(M);
  I(K);
  combiInit();

  ll dx = 0;
  FOR(i, 1, N) {
    dx += (i * (N - i)) % MOD;
    dx %= MOD;
  }
  dx *= (M * M) % MOD;
  dx %= MOD;

  ll dy = 0;
  FOR(j, 1, M) {
    dy += (j * (M - j)) % MOD;
    dy %= MOD;
  }
  dy *= (N * N) % MOD;
  dy %= MOD;

  ll dist = (dx + dy) % MOD;
  D(dist);

  ret = (dist * combi(N*M-2, K-2)) % MOD;

  P(ret);

}
