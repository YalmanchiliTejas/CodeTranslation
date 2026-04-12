#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = n - 1; i >= 0; i--)

#define ALL(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define UNIQUE(v) do{sort(v.begin(), v.end()); v.erase( unique(v.begin(), v.end()), v.end() );} while(0)

#define y0 y3487465
#define y1 y8687969

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

int N, A, B, C, D;

const int MAX_N = 10000;
ll fact[MAX_N + 1], fact_inv[MAX_N + 1];

ll mod_pow(ll x, ll n, ll p) {
  if(n == 0) return 1;
  ll res = mod_pow(x * x % p, n / 2, p);
  if(n & 1) res = res * x % p;
  return res;
}

void init(ll n, ll p) {
  fact[0] = 1;
  for(int i = 0; i < n; i++) {
    fact[i + 1] = fact[i] * (i + 1) % p;
  }
  fact_inv[n] = mod_pow(fact[n], p - 2, p);
  for(int i = n - 1; i >= 0; i--) {
    fact_inv[i] = fact_inv[i + 1] * (i + 1) % p;
  }
}


int main(){
  cin >> N >> A >> B >> C >> D;

  init(10000, MOD);

  ll dp[B + 1][N + 1];
  REP(i, A) REP(j, N + 1) dp[i][j] = 0;
  REP(i, B) dp[i][0] = 1;
  for(int i = A; i <= B; i++) {
    REP(j, N + 1) {
      dp[i][j] = dp[i - 1][j];
      for(int k = C; k <= min(j / i, D); k++) {
        dp[i][j] += dp[i - 1][j - i * k] * fact[N - j + i * k] % MOD * fact_inv[N - j] % MOD * mod_pow(fact_inv[i], k, MOD) % MOD * fact_inv[k] % MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[B][N] << endl;

  return 0;
}
