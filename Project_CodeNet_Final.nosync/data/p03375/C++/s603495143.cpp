#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,Mod;
int f[3010][3010];
int C[3010][3010];
int main()
{
	scanf("%d %d",&n,&Mod);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		{
			f[i][j+1]=(f[i][j+1]+f[i-1][j])%Mod;
			f[i][j]=(f[i][j]+(long long)f[i-1][j]*(j+1))%Mod;
		}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=0,val=1;
		for(int j=1;j<=n-i;j++)
			val=(val+val)%Mod;
		int cur=1;
		for(int j=0;j<=i;j++)
		{
			sum=(sum+(long long)cur*f[i][j])%Mod;
			cur=(long long)cur*val%Mod;
		}
		cur=2;
		for(int j=1;j<=n-i;j++)
			cur=(long long)cur*cur%Mod;
		if(i&1)
			ans=(ans-(long long)C[n][i]*cur%Mod*sum%Mod+Mod)%Mod;
		else ans=(ans+(long long)C[n][i]*cur%Mod*sum)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}