#include <bits/stdc++.h>
using namespace std;
#define N 110
#define mod 1000000007
typedef long long ll;
ll h[N],a[N],dp[N][N];
inline ll Pow(ll a,ll b,int p=mod) {
    if (b<=0) return 1; ll res=1;
    for (;b;b>>=1,a=1LL*a*a%p)
        if (b&1) res=1LL*res*a%p;
    return res;
}
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int main() {
    int n=read(),tot=0; dp[0][0]=1;
    for (int i=1;i<=n;i++) a[++tot]=h[i]=read();
    sort(a+1,a+tot+1),tot=unique(a+1,a+tot+1)-a-1;
    for (int i=1;i<=n;i++) h[i]=lower_bound(a+1,a+tot+1,h[i])-a;
    for (int i=1;i<=n;i++) {
        dp[i][0]=dp[i-1][0]*2%mod;
        for (int j=h[i]+1;j<=h[i-1];j++) dp[i][0]=(dp[i][0]+dp[i-1][j]*2%mod)%mod;
        ll tmp=Pow(2,a[h[i]]-a[h[i-1]]);
        for (int j=1;j<=min(h[i-1],h[i]);j++) dp[i][j]=dp[i-1][j]*tmp%mod;
        for (int j=h[i-1]+1;j<=h[i];j++) 
            if (dp[i][j]+j==1) dp[i][j]=dp[i-1][0]*(Pow(2,a[j])-2)%mod*Pow(2,a[h[i]]-a[j])%mod;
            else dp[i][j]=dp[i-1][0]*2*(Pow(2,a[j]-a[j-1])-1)%mod*Pow(2,a[h[i]]-a[j])%mod;
    }
    ll res=0;
    for (int i=0;i<=tot;i++) res=(res+dp[n][i])%mod;
    printf("%lld\n",res);
    return 0;
}