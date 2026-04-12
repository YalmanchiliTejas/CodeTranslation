#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
typedef long long LL;
 
const int N=3005;
 
int n,MOD,jc[N],ny[N],s[N][N];
 
int ksm(int x,int y,int mo)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%mo;
		x=(LL)x*x%mo;y>>=1;
	}
	return ans;
}
 
int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}
 
int main()
{
	scanf("%d%d",&n,&MOD);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	s[0][0]=1;
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=i;j++)
			(s[i][j]=s[i-1][j-1]+(LL)s[i-1][j]*j%MOD)%=MOD;
	int ans=0;
	for (int i=0;i<=n;i++)
	{
		int w=0;
		for (int j=0;j<=i;j++)
			(w+=(LL)ksm(ksm(2,n-i,MOD),j,MOD)*s[i+1][j+1]%MOD)%=MOD;
		w=(LL)w*ksm(2,ksm(2,n-i,MOD-1),MOD)%MOD*C(n,i)%MOD;
		if (i&1) (ans-=w)%=MOD;
		else (ans+=w)%=MOD;
	}
	printf("%d",(ans+MOD)%MOD);
	return 0;
}