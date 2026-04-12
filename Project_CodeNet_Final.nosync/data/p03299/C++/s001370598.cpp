#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 105
int n,f[N][N],h[N],w[N],m;
int ksm(int x,int y)
{
	int s = 1;
    for(int i = y; i > 0; i >>= 1){
    	if(i & 1) s = 1ll * s * x % mod;
    	x = 1ll * x * x % mod;
	}
    return s;
}
 
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&h[i]),w[++m]=h[i];
    std::sort(w+1,w+m+1);
    m=std::unique(w+1,w+m+1)-w-1;
    for (int i=1;i<=n;i++) h[i]=std::lower_bound(w+1,w+m+1,h[i])-w;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=h[i]+1;j<=h[i-1];j++) (f[i][0]+=f[i-1][j]*2%mod)%=mod;
        (f[i][0]+=f[i-1][0]*2%mod)%=mod;
        for (int j=1;j<=h[i];j++)
        {
            f[i][j]=(ll)f[i-1][j]*ksm(2,w[h[i]]-w[h[i-1]])%mod;
            if (h[i-1]>=j) continue;
            if (j>1) (f[i][j]+=(ll)f[i-1][0]*(ksm(2,w[j]-w[j-1])-1)%mod*2%mod*ksm(2,w[h[i]]-w[j])%mod)%=mod;
            else (f[i][j]+=(ll)f[i-1][0]*(ksm(2,w[j])-2)%mod*ksm(2,w[h[i]]-w[j])%mod)%=mod;
        }
    }
    int ans=0;
    for (int i=0;i<=m;i++) (ans+=f[n][i])%=mod;
    printf("%d",ans);
    return 0;
}