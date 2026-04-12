#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 510000;
const int MOD = 1000000007;
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
int main(void){
    int n,m,k; cin>>n>>m>>k;
    ll ans = 0, ans2=0;
    COMinit();
    for(int i=1;i<n;i++){
        ll tmp=0;
        ll pattern = (n-i)*m*m;
        tmp += pattern * i;
        tmp %= MOD;
        tmp *= COM(n*m-2, k-2);
        tmp %= MOD;
        ans+=tmp; ans%=MOD;
    }
    //ans *= COM(n*m-2, k-2);
    //cout<<ans%MOD<<endl;
    ans %= MOD;
    for(int i=0;i<m;i++){
        ll pattern = (m-i)*n*n;
        ll tmp=0;
        tmp += pattern * i;
        tmp%= MOD;
        tmp *= COM(n*m-2, k-2);
        tmp%= MOD;
        ans2+=tmp; ans2%= MOD;
    }
    ans2%= MOD;
    //ans *= COM(n*m-2, k-2);
    cout<<(ans+ans2) %MOD<<endl;
}
