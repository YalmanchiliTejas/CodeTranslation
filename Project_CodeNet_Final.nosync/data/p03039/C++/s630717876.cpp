#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000
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

// 二項係数計算
long long COM(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
  COMinit();
  ll N,M,K;
  cin>>N>>M>>K;
  ll memo=COM(N*M-2ll,K-2ll);
  ll x=1ll;
  ll y=1ll;  
  x=N*(N-1ll)*(N+1ll);
  x/=6ll;
  x%=MOD;
  x*=M;
  x%=MOD;
  x*=M;
  x%=MOD;
  y=M*(M-1ll)*(M+1ll);
  y/=6ll;
  y%=MOD;
  y*=N;
  y%=MOD;
  y*=N;
  y%=MOD;
  ll ans=x+y;
  ans%=MOD;
  ans*=COM(N*M-2ll,K-2ll);
  ans%=MOD;
  cout<<ans;
}
