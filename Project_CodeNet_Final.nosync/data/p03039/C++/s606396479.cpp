#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
LL f[200005], rf[200005];
LL sum[200005];
LL pw(LL a, LL b){
    LL res = 1;
    while(b){
        if(b%2 == 1) res = (res*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return res;
}
LL ncr(int a, int b){
    return f[a]*rf[b]%mod*rf[a-b]%mod;
}
int main(){
    f[0] = 1;
    for(int i=1;i<=200000;i++) f[i] = (f[i-1]*i)%mod;
    for(int i=0;i<=200000;i++) rf[i] = pw(f[i], mod-2);
    for(int i=1;i<=200000;i++) sum[i] = (sum[i-1] + i)%mod;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    LL ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ri = m-j;
            ans = (ans + sum[ri]%mod*ncr(n*m-2, k-2)%mod*ncr(n, 1))%mod;

            ri = n-i;
            ans = (ans + sum[ri]%mod*ncr(n*m-2, k-2)%mod*ncr(m, 1))%mod;
        }
    }   
    printf("%lld\n", ans);
}