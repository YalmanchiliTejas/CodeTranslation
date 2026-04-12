#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;
const int N_MAX = 2*pow(10,5);

// factorial(階乗)の計算

ll fac[N_MAX+1] ={};

ll c_fac(int n) {
  if (fac[n]!=0) return fac[n];
  if (n==0) return fac[n]=1;
  return fac[n] = (c_fac(n-1)*n)%MOD;
}

// inverse(逆元)の計算

ll inv(ll a,ll m) {
  ll b = m, x = 1, y = 0;
  while (b!=0) {
    ll d = a/b;
    a -= b*d; swap(a, b);
    x -= y*d; swap(x, y);
  }
  return x>=0 ? x : x+m;
}

// combinataionの計算

ll nck(ll n, ll k) { 
  if (n<k) return 0;
  ll nume = fac[n];
  ll deno = ( inv(fac[n-k],MOD) * inv(fac[k],MOD) ) % MOD;
  return ( nume * deno ) % MOD;
}

int main() {
  ll N, M, K; cin >> N >> M >> K;

  c_fac(N_MAX+1);

  ll result = 0;
  ll part = 0;
  rep(i, N) { part += i*(N-i)*2*pow(M,2); part%=MOD; }
  rep(i, M) { part += i*(M-i)*2*pow(N,2); part%=MOD; }
  result += nck(K, 2) * part;
  result %= MOD;
  result *= nck(N*M-2, K-2);
  result %= MOD;
  result *= fac[K-2];
  result %= MOD;
  result *= inv(fac[K], MOD);
  result %= MOD;

  cout << result << endl;
  return 0;
}