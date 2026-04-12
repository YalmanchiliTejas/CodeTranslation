#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    COMinit();
    ll ans=0;
    for(int i=1;i<=m-1;i++){
        ans=(ans+((m-i)*i)%MOD*(n*n)%MOD)%MOD;
    }
    for(int i=1;i<=n-1;i++){
        ans=(ans+((n-i)*i)%MOD*(m*m)%MOD)%MOD;
    }
    ans=(ans*COM(n*m-2,k-2))%MOD;
    cout<<ans<<endl;
}
