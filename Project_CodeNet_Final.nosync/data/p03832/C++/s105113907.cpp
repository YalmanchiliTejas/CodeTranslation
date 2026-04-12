#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MAX = 100000;
const ll mod = 1000000007;
const ll MOD = 1e9+7;

ll fac[MAX], finv[MAX], inv[MAX];
ll inv2[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[0] = inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        //inv2[i] = inv[i];
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

ll dp[6][32000];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    dp[0][0]=1;
    ll x = 1;
    COMinit();
    for(ll i=b;i>=a;i--){
        for(ll j=0;j<=n;j++) dp[x][j] = dp[x^1][j];
        ll mul=1,tmp=1;
        for(ll j=0;j<c;j++){
            tmp *= COM(i*c-i*j,i);
            tmp %= mod;
        }
        tmp *= finv[c];
        tmp %= mod;
        for(ll j=c;j<=d;j++){
            if(i*j > n) break;
            if(j!=c){
                tmp *= COM(i*j,i);
                tmp %= mod;
                tmp *= inv[j];
                tmp %= mod;
            }
            mul = tmp; 
            ll now = i*j;
            for(ll k=n;k>=i*j;k--){
                dp[x][k] += (dp[x^1][k-i*j] * mul)%mod;
                dp[x][k] %= mod;
                now++;
                mul *= (now * inv[now-i*j])%mod;
                mul %= mod;               
            }
        }
        x ^= 1;
    }
    cout << dp[x^1][n] << endl;
}