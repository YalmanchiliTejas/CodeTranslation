#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

// factorial(階乗)の計算
const int N_MAX = pow(10,3)*2;
ll fac[N_MAX+1] = {};
ll inv_fac[N_MAX+1] = {};
ll c_fac(int n=N_MAX) {
  if (fac[n]!=0) return fac[n];
  if (n==0) return fac[n]=1;
  return fac[n] = (c_fac(n-1)*n)%MOD;
}

// inverse(逆元)の計算
ll inv(ll a,ll m=MOD) {
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
  c_fac(n);
  if (n<k) return 0;
  ll nume = fac[n];
  ll deno = ( inv(fac[n-k]) * inv(fac[k]) ) % MOD;
  return ( nume * deno ) % MOD;
}

int main() {
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  c_fac();
  rep(i,N_MAX+1) inv_fac[i] = inv(fac[i]);

  ll dp[(B-A+1)+1][N+1] = {}; dp[0][0] = 1;
  ll count = 0;
  repr(i,A,B+1) {
    rep(j,N+1) dp[i-A+1][j] = dp[i-A][j];
    repr(j,C*i,N+1) {
      ll pfi = 1; rep(k,C) { pfi *= fac[i]; pfi %= MOD; }
      for (int k=C; j-k*i>=0&&k<=D; k++) {
        ll num = dp[i-A][j-k*i];
        num *= fac[N-(j-k*i)]; num %= MOD;
        num *= inv_fac[N-j]; num %= MOD;
        num *= inv(pfi); num %= MOD;
        num *= inv_fac[k]; num %= MOD;
        dp[i-A+1][j] += num; dp[i-A+1][j] %= MOD;
        pfi *= fac[i]; pfi %= MOD;
      }
    }
  }
  // rep(i,B-A+2) debug(dp[i],dp[i]+N+1);
  ll result = dp[B-A+1][N];
  cout << result << endl;
  return 0;
}