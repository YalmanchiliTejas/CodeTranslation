#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=3005;
LL n,m;
LL JC[N],inv[N];
LL s[N][N];
LL pow (LL x,LL y,LL MOD)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=pow(x,y>>1,MOD);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL C (LL x,LL y)
{
	if (x<y) return 0;
	return JC[x]*inv[y]%m*inv[x-y]%m;
}
int main()
{
	//printf("%lld\n",123456791LL*123456791LL);
	scanf("%lld%lld",&n,&m);
	JC[0]=1;for (LL u=1;u<=n;u++) JC[u]=JC[u-1]*u%m;
	inv[n]=pow(JC[n],m-2,m);for (LL u=n-1;u>=1;u--) inv[u]=inv[u+1]*(u+1)%m;inv[0]=1;
	s[0][0]=1;
	for (LL u=1;u<=n+1;u++)
		for (LL i=1;i<=u;i++)
			s[u][i]=(s[u-1][i-1]+s[u-1][i]*i%m)%m;
	LL ans=0;
//	printf("%lld\n",JC[n]);
	for (LL u=0;u<=n;u++)//有多少个不和法的 
	{
		LL w=0;
		for (LL i=0;i<=u;i++)	w=(w+pow(pow(2,n-u,m),i,m)*s[u+1][i+1]%m)%m;
		//	printf("%lld %lld\n",u,w);
		w=w*C(n,u)%m*pow(2,pow(2,n-u,m-1),m)%m;
		if (u&1) ans=ans-w;
		else ans=ans+w;
	/*	printf("%lld %lld\n",u,w);
		system("pause");*/
		ans=(ans%m+m)%m;
	}
	printf("%lld\n",ans);
	return 0;
}