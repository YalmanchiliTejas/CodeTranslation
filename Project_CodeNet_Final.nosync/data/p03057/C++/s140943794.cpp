#include<bits/stdc++.h>
using namespace std;
#define re register
char ss[1001000];
const int mod=1e9+7;
int f[1001000],ff[1001000][2][2],x[2];
int main()
{
	re int n,m,ans=1,xx=0,mmx=1<<30;
	scanf("%d%d",&n,&m);
	scanf("%s",ss+1);
	for(re int i=1;i<=m;i++)
	{
		if(ss[i]!=ss[1])
		{
			if(ans)mmx=xx+2-(xx&1);
			else if((xx&1)&&mmx>xx+1)mmx=xx+1;
			xx=0;ans=0;
		}else xx++;
	}
	if(ans==1)
	{
		ff[1][0][0]=ff[1][1][1]=1;
		for(re int i=2;i<=n;i++)
		{
			for(re int j=0;j<=1;j++)
			{
				ff[i][j][0]=(ff[i-1][j][0]+ff[i-1][j][1])%mod;
				ff[i][j][1]=ff[i-1][j][0];
			}
		}
		printf("%lld\n",((long long)ff[n][0][0]+ff[n][0][1]+ff[n][1][0])%mod);
		return 0;
	}
	f[0]=f[2]=1;
	for(re int i=4;i<=n;i++)
	{
		f[i]=(2ll*f[i-2]+(i-mmx-2>=0?mod-f[i-mmx-2]:0))%mod;
		//printf("**%d %d %d\n",i,f[i],mmx);
	}
	for(re int i=2;i<=mmx&&i<=n;i+=2)ans=(ans+(long long)i*f[n-i])%mod;
	printf("%d\n",ans);
}