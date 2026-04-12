#include<bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll N;
ll f[1100][1100],g[1100];
ll a[1100],H[1100],lisan[1100],lcnt;
ll &ml=lcnt;
ll ans;
ll qpow(ll a,ll b) {
    ll ans=1;
    for(;b;b>>=1,a=(a*a)%mod) if(b&1) ans=(ans*a)%mod;
    return ans;
}

int main() {
    //cerr<<qpow(2,0)<<endl;
    scanf("%lld",&N);
    for(int i=1;i<=N;++i) scanf("%lld",a+i),lisan[i]=a[i];
    sort(lisan+1,lisan+N+1);
    lcnt=unique(lisan+1,lisan+N+1)-lisan-1;
    for(int i=1;i<=N;++i) H[i]=lower_bound(lisan+1,lisan+lcnt+1,a[i])-lisan;
    //for(int i=1;i<=N;++i) printf("H[%d]=%lld\n",i,H[i]);
    g[1]=2;
    for(int i=1;i<=H[1];++i) f[1][i]=qpow(2,a[1]-lisan[i])*(qpow(2,lisan[i])-2);//,tt(1,i);
    for(int i=H[1]+1;i<=ml;++i) f[1][i]=f[1][i-1];//,tt(1,i);
    for(int i=2;i<=N;++i) {
        for(int j=1;j<=H[i];++j) {
            f[i][j]+=f[i-1][j]%mod*qpow(2,max(0ll,a[i]-a[i-1]))%mod;
            f[i][j]%=mod;
            if(j>H[i-1]) {
                f[i][j]+=2*g[i-1]%mod*qpow(2,a[i]-lisan[j])%mod*(qpow(2,lisan[j]-a[i-1])-1)%mod;
                f[i][j]%=mod;
            }
            //tt(i,j);
        }
        for(int j=H[i]+1;j<=ml;++j) f[i][j]=f[i][j-1];
        if(H[i-1]<=H[i]) g[i]=g[i-1]*2%mod;
        else g[i]=(g[i-1]*2%mod+(f[i-1][H[i-1]]-f[i-1][H[i]]+mod)*2%mod)%mod;
        g[i]=(g[i]%mod+mod)%mod;
        //printf("g[%d]=%lld\n",i,g[i]);
    }
    ans=(g[N]+f[N][ml])%mod;
    //printf("ans=%lld\n",ans);
    printf("%lld\n",ans%mod);
    return 0;
}
