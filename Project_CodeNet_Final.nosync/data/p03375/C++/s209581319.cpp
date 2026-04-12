#include<cstdio>
#define N 3003
#define ll long long
inline int calc(int x,int y,int m)
{
	int z=1;
	for(;y;x=(ll)x*x%m,y>>=1)if(y&1)z=(ll)x*z%m;
	return z;
}
int a[N],b[N],f[N][N],g[N],i,j,m,n,s,t;
int main()
{
	scanf("%d%d",&n,&m),*a=a[1]=*b=b[1]=1;
	for(i=2;i<=n;i++)a[i]=(ll)a[i-1]*i%m,b[i]=(ll)(m-m/i)*b[m%i]%m;
	for(i=1;i<=n;i++)b[i]=(ll)b[i-1]*b[i]%m;
	for(i=0;i<=n;i++)for(j=f[i][0]=1;j<=i;j++)f[i][j]=(f[i-1][j-1]+f[i-1][j]*(j+1ll))%m;
	for(i=n,s=1;i>=0;i--,s=(s<<1)%m)for(j=0,t=1;j<=i;j++,t=(ll)s*t%m)g[i]=(g[i]+(ll)f[i][j]*t)%m;
	for(i=s=0;i<=n;i++)i&1?s=(s+(ll)(m-a[n])*b[i]%m*b[n-i]%m*g[i]%m*calc(2,calc(2,n-i,m-1),m))%m:s=(s+(ll)a[n]*b[i]%m*b[n-i]%m*g[i]%m*calc(2,calc(2,n-i,m-1),m))%m;
	return 0*printf("%d\n",s);
}