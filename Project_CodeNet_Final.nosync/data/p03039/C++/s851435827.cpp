#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMInit(void){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i< MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] %MOD;
    }
}

long long COM(long long n, long long k){
    if (n < k){return 0;}
    if (n < 0 || k < 0){return 0;}
    return fac[n]*(finv[k] * finv[n-k]%MOD)%MOD;
}

int main(void) {
    ll n,m,k;
    cin >> n >> m >> k;
    COMInit();
    ll res = COM(n*m-2, k-2);
    ll tmp=0;
    for(ll i=1;i<=n-1;i++){
        tmp += i*(n-i)%MOD*m*m%MOD;
        tmp %= MOD;
    }
    for(ll i=1;i<=m-1;i++){
        tmp += i*(m-i)%MOD*n*n%MOD;
        tmp %= MOD;
    }
    cout << res*tmp%MOD << endl;
    return 0;
}
