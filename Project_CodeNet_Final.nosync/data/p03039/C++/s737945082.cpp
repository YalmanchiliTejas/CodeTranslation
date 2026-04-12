#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  ll N,M,K;
  cin>>N>>M>>K;
  ll g=1ll;
  g*=COM(N*M-2,K-2);
  ll ans=0ll;
  rep(i,M){
    ll p=g*N*N;
    p%=MOD;
    ll q=0ll;
    q=q+((i+1ll)*i)/2ll;
    q=q+((M-i)*(M-i-1ll))/2ll;
    q%=MOD;
    ans+=p*q;
    ans%=MOD;
  }
  rep(i,N){
    ll p=g*M*M;
    p%=MOD;
    ll q=0ll;
    q+=((i+1ll)*i)/2ll;
    q+=((N-i)*(N-i-1ll))/2ll;
    q%=MOD;
    ans+=p*q;
    ans%=MOD;
  }
  ans*=modinv(2ll,MOD);
  ans%=MOD;
  cout<<ans<<endl;
}