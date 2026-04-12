#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

const int MAX = 510000;
const ll MOD = 1000000007;
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

long long FINV(int n){
    if (n < 0) return 0;
    return finv[n];
}

ll dp[1100][1100];

int main() {
    COMinit();
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    ll ans = 0;

    rep(i,1100)dp[i][0] = 1;

    srep(i,a,b+1){
        rep(j,n+1)dp[i][j] = dp[i-1][j];
        rep(j,n+1){
            if(dp[i-1][j] == 0)continue;
            if(j + i * c > n)break;
            ll invv = 1;
            rep(k,c){
                invv = invv * finv[i] % MOD;
            }
            srep(k,c,d+1){
                if(j + i * k > n)break;
                dp[i][j+i*k] += dp[i-1][j] * COM(n-j, i*k) % MOD * FINV(k) % MOD * fac[i*k] % MOD * invv % MOD;
                dp[i][j+i*k] %= MOD;
                invv = invv * finv[i] % MOD;
            }
        }
    }

    srep(i,a,b+1){
        ans += dp[i][n];
        ans %= MOD;
        // cout << dp[i][n] << endl;
    }

    cout << dp[b][n] << endl;
    return 0;
}

