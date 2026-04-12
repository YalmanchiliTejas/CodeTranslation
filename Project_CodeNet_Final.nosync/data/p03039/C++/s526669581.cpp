#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;

    COMinit();

    ll ans = 0;

    rep(i,n){
        rep(j,m){
            ll ii = i;
            ll jj = j;
            ll x = (n-1-ii)*(n-ii)/2%MOD*m%MOD;
            ll y = ((jj*(jj+1)/2%MOD)*(n-1-ii)%MOD + (m-1-jj)*(m-jj)/2%MOD*(n-ii)%MOD)%MOD;
            ans += (x+y)%MOD * COM(n*m-2,k-2) % MOD;
            ans %= MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}
 
 
