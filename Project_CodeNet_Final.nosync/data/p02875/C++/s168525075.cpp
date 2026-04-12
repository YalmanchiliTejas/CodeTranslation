#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = 998244353;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;

const int N_MAX = pow(10,7)/2;

// factorial(階乗)の計算

ll fac[N_MAX+1] ={};

ll c_fac(int n) {
  if (fac[n]!=0) return fac[n];
  if (n==0) return fac[n] = 1;
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
  int N; cin >> N;

  ll com[N/2] = {}; ll pow2 = 1;
  c_fac(N/2+1);
  rep(i,N/2) {
    com[(N/2-1)-i] = (pow2 * nck(N/2, N/2-i)) % MOD;
    pow2 = (pow2*2) % MOD;
  }
  ll sum[N/2] = {}; rep(i,N/2) sum[i] = (i==0) ? com[(N/2-1)-i] : (sum[i-1] + com[(N/2-1)-i]) % MOD;
  ll result = 1, tmp = 0; 
  rep(i,N) { result *= 3; result %= MOD; }
  rep(i,N/2) { tmp += com[i] * sum[i] * 2; tmp %= MOD; }
  result = ( result - tmp + MOD ) % MOD;
  cout << result << endl;
  // rep(i, N/2) cout << com[i] << " " << sum[i] << endl;
  return 0;
}