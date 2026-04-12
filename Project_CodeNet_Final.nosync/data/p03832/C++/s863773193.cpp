#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, a, b, c, d;
ll dyn[1100][1100], MOD = 1000000007;
ll fac[1100], fnv[1100], fnp[1100][1100];

ll power(ll a, ll n) {
    if (!n) return 1;
    ll tmp = power(a,n/2);
    return tmp*tmp%MOD*((n&1)?a:1)%MOD;
}

int main() {
    int i, j, k;

    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    dyn[0][a-1] = 1;
    fac[0] = fnv[0] = 1;
    for (i=1;i<=n;i++) {fac[i]=fac[i-1]*i%MOD; fnv[i] = power(fac[i],MOD-2);}
    for (i=0;i<=n;i++) for (j=0;j<=n;j++) fnp[i][j] = power(fnv[i],j);
    for (i=0;i<=n;i++) {
        for (j=a;j<=b;j++) {
            ll &res = dyn[i][j]; res = dyn[i][j-1];
            for (k=c;k<=d&&i-k*j>=0;k++) {
                res += dyn[i-j*k][j-1]*fac[i]%MOD*fnv[i-k*j]%MOD*fnp[j][k]%MOD*fnv[k]%MOD;
                res %= MOD;
            }
        }
    }
    printf("%lld\n",dyn[n][b]);

    return 0;
}
