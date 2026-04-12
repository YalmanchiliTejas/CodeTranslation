#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105,mod=1e9+7;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline int ksm(int x,int y)
{
	if(y<=0) return 1;//为什么要加这一句？ 
	int res=1;
	for(;y;y>>=1,x=(x*x)%mod)if(y&1)res=(res*x)%mod;
	return res;
}
int a[N],Has[N],tot,f[N][N],n,ans;
signed main(void)
{
	n=read();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		Has[++tot]=a[i];
	}
	sort(Has+1,Has+tot+1);
	tot=unique(Has+1,Has+tot+1)-Has-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(Has+1,Has+tot+1,a[i])-Has;
	for(int i=1;i<=n;i++)
	{
		int now=ksm(2,Has[a[i]]-Has[a[i-1]]);
		f[i][0]=(f[i-1][0]<<1)%mod;
		for(int j=a[i]+1;j<=a[i-1];j++)f[i][0]=(f[i][0]+((f[i-1][j])<<1)%mod)%mod;
		for(int j=1;j<=min(a[i-1],a[i]);j++)f[i][j]=f[i-1][j]*now%mod;
		for(int j=a[i-1]+1;j<=a[i];j++)
		if(j==1)f[i][j]=f[i-1][0]*(ksm(2,Has[j])-2)%mod*ksm(2,Has[a[i]]-Has[j])%mod;
		else f[i][j]=(f[i-1][0]<<1)*(ksm(2,Has[j]-Has[j-1])-1)%mod*ksm(2,Has[a[i]]-Has[j])%mod;
	}
	for(int i=0;i<=tot;i++)ans=(ans+f[n][i])%mod;
	printf("%lld\n",ans);
	return 0;
}