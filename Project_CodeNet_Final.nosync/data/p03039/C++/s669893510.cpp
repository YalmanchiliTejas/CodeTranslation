#include <bits/stdc++.h>
using namespace std;
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
int main() {
    COMinit();
    int n,m,k;
    long long x=0,y=0,z,d,nn,mm,kk;
    cin >> n >> m >> k;
    z=COM(n*m-2,k-2); nn=n; mm=m; kk=k;
    for(d=1;d<n;d++) x=(x+(((d*(nn-d)%MOD)*mm%MOD)*mm%MOD))%MOD;
    for(d=1;d<m;d++) y=(y+(((d*(mm-d)%MOD)*nn%MOD)*nn%MOD))%MOD;
    cout << ((x+y)%MOD)*z%MOD << endl;
}
