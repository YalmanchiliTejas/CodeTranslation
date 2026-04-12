
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int MAXN=1000;
int n,a,b,c,d;
ll f[MAXN+10];
ll finv[MAXN+10];
ll dp[MAXN+10][MAXN+10];

ll qp(ll x,ll n) {
    ll ret=1;
    while (n) {
        if (n&1) ret=(ret*x)%MOD;
        n=n>>1;
        x=(x*x)%MOD;
    }
    return ret;
}

int main() {
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    f[0]=finv[0]=1;
    for (int i=1;i<=MAXN;i++) {
        f[i]=(f[i-1]*i)%MOD;
        finv[i]=qp(f[i],MOD-2);
    }
    for (int i=0;i<=n;i++) dp[0][i]=1;
    for (int j=a;j<=b;j++) {
        for (int i=1;i<=n;i++) {
            ll accum=1;
            dp[i][j]=dp[i][j-1];
            for (int k=1;k<c;k++) accum=(accum*finv[j])%MOD;
            for (int k=c;k*j<=i&&k<=d;k++) {
                accum=(accum*finv[j])%MOD;
                ll co1=(((f[i]*finv[k*j])%MOD)*finv[i-k*j])%MOD;
                ll co2=(((f[k*j]*finv[k])%MOD)*accum)%MOD;
                ll co=(co1*co2)%MOD;//printf("co1:%lld co2:%lld co:%lld\n",co1,co2,co);
                dp[i][j]=(dp[i][j]+(co*dp[i-k*j][j-1])%MOD)%MOD;
            }
            //printf("i:%d j:%d val:%lld\n",i,j,dp[i][j]);
        }
    }
    printf("%lld\n",dp[n][b]);
}