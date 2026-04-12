#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll N, M, K;
ll Comb[200005]; // NM-2Ci

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a) {
    return modpow(a, MOD - 2);
}

void init() {
  Comb[0] = 1ll;
  rep(i, K) {
    if (i==0) continue;
    Comb[i] = Comb[i-1]*(N*M-2-i+1)%MOD*modinv(i)%MOD;
  }
}

ll calc(ll x, ll L, ll L2) { // 一次元で差がx,長さがL, もう一次元の長さがL2
  return x*(L-x)%MOD*L2%MOD*L2%MOD;
}

int main() {
  INCANT;
  cin >> N >> M >> K;
  init();
  ll SUM=0ll;
  rep(i, M) {
    SUM+=calc(i, M, N);
    SUM%=MOD;
  }
  rep(i, N) {
    SUM+=calc(i, N, M);
    SUM%=MOD; 
  }
  cout << SUM*Comb[K-2]%MOD << "\n";
  return 0;
}