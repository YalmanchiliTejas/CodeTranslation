#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,a[1005],f[1005][2],st[100005],tp,ls[100005],rs[100005],inv2;
void dfs(int u,int fa)
{
	if(!u) return;
	dfs(ls[u],u),dfs(rs[u],u);
	int v=a[u]-a[fa];
	if(!ls[u]&&!rs[u])
	{
		f[u][1]=fpow(2,v);
	//	printf("u=%d,f=%d,%d\n",u,f[u][0],f[u][1]);
		return;
	} 
	if(!ls[u]||!rs[u])
	{
		int s=ls[u]+rs[u];
		f[u][0]=2ll*addmod(f[s][0]+f[s][1])%mod;
	//	f[u][0]=submod(f[u][0]-f[s][1]);
		f[u][1]=1ll*fpow(2,v)*f[s][1]%mod;
	//	printf("u=%d,f=%d,%d\n",u,f[u][0],f[u][1]);
		return;
	}
	f[u][0]=2ll*addmod(f[ls[u]][0]+2*f[ls[u]][1]%mod)*addmod(f[rs[u]][0]+2*f[rs[u]][1]%mod)%mod;
	f[u][0]=submod(f[u][0]-2ll*f[ls[u]][1]*f[rs[u]][1]%mod);
	f[u][1]=1ll*fpow(2,v)*f[ls[u]][1]%mod*f[rs[u]][1]%mod;
	//printf("u=%d,f=%d,%d\n",u,f[u][0],f[u][1]);
}
int main()
{
	inv2=fpow(2,mod-2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(tp>1&&a[st[tp-1]]>a[i])
		{
			rs[st[tp-1]]=st[tp];
			tp--;
		}
		if(tp&&a[st[tp]]>a[i]) ls[i]=st[tp],tp--;
		st[++tp]=i;
	}
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,ls=%d,rs=%d\n",i,ls[i],rs[i]);
	while(tp>1)
	{
		rs[st[tp-1]]=st[tp];
		tp--;
	}
	dfs(st[tp],0);
	printf("%d",addmod(f[st[tp]][0]+f[st[tp]][1]));
	return 0;
}