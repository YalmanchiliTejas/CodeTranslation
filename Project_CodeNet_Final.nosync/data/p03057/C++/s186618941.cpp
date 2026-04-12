#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int Mod=1000000007;
int a[200010];
char s[200010];
int f[200010],g[200010];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
		a[i]=s[i]=='B';
	if(a[1]){
		for(int i=1;i<=m;i++)
			a[i]^=1;
	}
	bool flag=true;
	for(int i=1;i<=m;i++)
		if(a[i])flag=false;
	if(flag){
		f[0]=1;
		g[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(i>1)f[i]=g[i-2];
			g[i]=(g[i-1]+f[i])%Mod;
		}
		int ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans+1ll*f[n-i]*i)%Mod;
		printf("%d\n",ans);
		return 0;
	}
	if(n&1){
		printf("0\n");
		return 0;
	}
	int lim=n;
	int lst=0;
	for(int i=1;i<=m;i++)
		if(a[i]){
			if(!lst)lim=min(lim,i-lst+1);
			else if((i-lst)%2==0)lim=min(lim,i-lst);
			lst=i;
		}
	lim/=2;
	f[0]=1;
	g[0]=1;
	for(int i=1;i<=n/2;i++)
	{
		f[i]=g[i-1];
		if(i-lim>0)f[i]=(f[i]-g[i-lim-1]+Mod)%Mod;
		g[i]=(g[i-1]+f[i])%Mod;
	}
	int ans=0;
	for(int i=1;i<=lim;i++)
		ans=(ans+1ll*i*2*f[n/2-i])%Mod;
	printf("%d\n",ans);
	return 0;
}