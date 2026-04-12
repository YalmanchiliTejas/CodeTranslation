#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long int ll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

#define MOD 1000000007

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll comb(int n, int r) {
  ll val = 1;
  ll din = 1;
  repi(a, n-r+1, n+1) val = (val * a) % MOD;
  repi(a, 1, r+1) din = (din * a) % MOD;
  val = (modinv(din, MOD) * val) % MOD;
  return val;
}

ll f_sum(ll m, ll n){
  ll val = 0;
  repi(i, 1, m+1)
    val = (val + i * i + (m-i+1) * (m-i+1)) % MOD;
  val = (val * n * n) % MOD;
  return val;
}

int main(){
  ll N, M, K;
  cin >> N >> M >> K;

  ll ans = (f_sum(N, M) + f_sum(M, N) - M*N*(2*M*N+M+N)) % MOD;
  if(ans < 0) ans += MOD;
  ans = (ans * comb(K, 2)) % MOD;
  ans = (ans * comb(M*N, K)) % MOD;
  ans = (modinv(2*M*N*(M*N-1) % MOD, MOD) * ans) % MOD;

  cout << ans << endl;
  return 0;
}
