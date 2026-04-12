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

// calc nCk mod p, O(n + log p)
// 1. init(n, p)
// 2. use mod_nck(n, k, p) 
const int MAX_N = 200000;
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

ll mod_nck(ll n, ll k, ll p) {
  return (fact[n] * fact_inv[k]) % p * fact_inv[n-k] % p;
}


ll N, M, K;

int main(){
  cin >> N >> M >> K;
  init(N * M, MOD);
  ll x = 0, y = 0;
  REP(i, N) x = (x + i * (N - i) * M * M) % MOD;
  REP(j, M) y = (y + j * (M - j) * N * N) % MOD;
  ll ans = mod_nck(N * M - 2, K - 2, MOD) * ((x + y) % MOD) % MOD;

  cout << ans << endl;

  return 0;
}
