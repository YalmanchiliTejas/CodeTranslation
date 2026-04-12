#include<cstdio>
#include<algorithm>
using namespace std;
int n,MOD;
int s[3100][3100],sum[3100],mi[3100],inv[3100],w[9000010],g[3100],ws[3100];
int ans;
int mo(int x)
{
	if (x>=MOD) return x-MOD;
	return x;
}
int power(int x,int y)
{
	int ans=1,t=x;
	while (y)
	{
		if (y%2) ans=1ll*ans*t%MOD;
		t=1ll*t*t%MOD;
		y/=2;
	}
	return ans;
}
void init()
{
	mi[0]=mi[1]=1;
	for (int i=2;i<=n;i++) mi[i]=1ll*mi[i-1]*i%MOD;
	inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for (int i=2;i<=n;i++) inv[i]=1ll*inv[i-1]*inv[i]%MOD;
	w[0]=1; g[0]=2;
	ws[0]=1; 
	for (int i=1;i<=n*n;i++) w[i]=mo(w[i-1]+w[i-1]);
	for (int i=1;i<=n;i++) ws[i]=ws[i-1]*2%(MOD-1),g[i]=power(2,ws[i]);
	s[0][0]=1;
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=i;j++)
			s[i][j]=mo(s[i-1][j-1]+1ll*s[i-1][j]*j%MOD);
}
int C(int x,int y)
{
	if (x<y) return 0;
	return 1ll*mi[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main()
{
	scanf("%d%d",&n,&MOD);
	init();
	for (int k=0;k<=n;k++) 
		{
			int i=n-k;
			int cas=k%2?MOD-1:1;
		//	printf("%d %d %d %d %d %d\n",mi[n],inv[k],inv[i],inv[j],sum[i],g[j]);
			for (int j=0;j<=k;j++)
				ans=mo(ans+1ll*cas*C(n,k)%MOD*s[k+1][j+1]%MOD*w[j*i]%MOD*g[i]%MOD);
		//	printf("%d %d %d\n",k,i,ans);
		}
	printf("%d\n",ans);
}