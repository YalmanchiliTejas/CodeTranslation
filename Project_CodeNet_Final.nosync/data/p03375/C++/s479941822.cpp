#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=3005;
int n,md,i,j,k,x,w,u,s2[N][N],ans,pw2[N],Pw2[N],jc[N],rjc[N],inv[N];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	scanf("%d%d",&n,&md);
	inv[1]=1;
	for(i=2;i<=n;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=n;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	s2[0][0]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j)
			s2[i][j]=(s2[i-1][j-1]+1ll*s2[i-1][j]*j)%md;
	pw2[0]=Pw2[0]=1;
	for(i=1;i<=n;++i)
		pw2[i]=1ll*pw2[i-1]*2%(md-1),Pw2[i]=1ll*Pw2[i-1]*2%md;
	for(i=0;i<=n;++i)
	{
		
		w=0;
		for(k=0,x=1;k<=i;++k,x=1ll*x*Pw2[n-i]%md)
		{
			u=1ll*s2[i][k+1]*(k+1)%md;
			u=(u+s2[i][k])%md;
			w=(w+1ll*u*x)%md;
		}
		w=1ll*w*pw(2,pw2[n-i])%md;
		ans=(ans+1ll*C(n,i)*w%md*(i&1?-1:1)+md)%md;
	}
	printf("%d",ans);
	return 0;
}