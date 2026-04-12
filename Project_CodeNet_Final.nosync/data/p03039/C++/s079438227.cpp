#define Bobyama
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define len(X) ((int)(X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N, M, K;

ll calc() {
    ll t1 = 0;
    for (ll i = 0; i < M; ++i) {
        t1 += mod(i*(M-i), MOD);
        t1 = mod(t1, MOD);
    }
    t1 = mod(t1*N%MOD*N%MOD, MOD);

    ll t2 = 0;
    for (ll i = 0; i < N; ++i) {
        t2 += mod(i*(N-i), MOD);
        t2 = mod(t2, MOD);
    }
    t2 = mod(t2*M%MOD*M%MOD, MOD);

    return mod((t1 + t2)*2, MOD);
}

const int MAX_N = 200000;
ll fact[MAX_N+1];
ll inv_fact[MAX_N+1];

//整数a,bに対し、ax + by = gcd(a,b) を満たす整数x,y,gcd(a,b) を計算する
ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

//ax ≡ gcd(a,m) (mod m) を満たすxを計算する。
ll mod_inverse(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x%m) % m;
}


void init(ll n, ll mod) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1]*i)%mod;

  for (int i = 0; i <= n; ++i) inv_fact[i] = mod_inverse(fact[i], mod);
}

ll mod_comb(ll n, ll r, ll mod) {
  return fact[n]*inv_fact[r]%mod*inv_fact[n-r]%mod;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M >> K;
  init(N*M, MOD);

  ll t = calc();

  ll ans = mod(t*mod_comb(K, 2, MOD)%MOD*fact[M*N-2]%MOD*inv_fact[N*M-K]%MOD*inv_fact[K], MOD);

  cout << ans << endl;

  return 0;
}
