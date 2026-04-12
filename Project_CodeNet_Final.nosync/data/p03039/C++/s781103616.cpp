#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
const int INF = 1<<30;
const ll MOD = 1e9+7;
const double EPS = 1e-9;

ll ex_euclid(ll a, ll b, ll &x, ll &y){
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }
  ll d = ex_euclid(b, a%b, y, x);
  y -= a/b * x;
  return d;
}

ll modinv(ll a, ll p){
  ll x, y, d;
  d = ex_euclid(a, p, x, y);
  assert(d == 1);
  return ((x % MOD) + MOD) % MOD;
}

const int maxN = 500001;
ll fac[maxN], inv[maxN], finv[maxN];

// O(N) precomputation
void modnCk_init(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i=2; i<maxN; i++){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = modinv(i, MOD); // O(logN)
//    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD; // O(1)
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

// O(K)
ll modnCk_bigN(int N, int K){
  if (N < K) return 0;
  if (K == 0) return 1;
  ll ret = N;
  inv[1] = 1;
  for (int k=2; k<=K; k++){
    inv[k] = MOD - inv[MOD%k] * (MOD/k) % MOD;
    ret = ret * ((N-k+1) * inv[k] % MOD) % MOD;
  }
  return ret;
}

// O(1) with O(N) precomputation
ll modnCk(int n, int k){
  if (n < k) return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main(int argc, const char * argv[]) {
  int N, M, K;
  cin >> N >> M >> K;
  
  modnCk_init();
  ll c = modnCk(N*M-2, K-2);
  ll ans = 0;
  for (int d=1; d<N; d++)
    ans = (ans + ((c * d % MOD) * (M * M % MOD) % MOD) * (N-d) % MOD) % MOD;
  
  for (int d=1; d<M; d++)
    ans = (ans + ((c * d % MOD) * (N * N % MOD) % MOD) * (M-d) % MOD) % MOD;
  
  cout << ans << endl;
  return 0;
}