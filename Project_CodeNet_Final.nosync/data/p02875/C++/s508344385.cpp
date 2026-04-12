#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,ans,jc[10000010],jcv[10000010];
int main()
{
	scanf("%d",&n);
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[n]=kpow(jc[n],mod-2);
	for(int i=n;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
	int po=1;
	for(int i=n;i>n/2;--i)
	{
		ans=(ans+1ll*jcv[i]*jcv[n-i]%mod*po)%mod;
		(po+=po)>=mod?po-=mod:0;
	}
	ans=(kpow(3,n)+2ll*(mod-ans)*jc[n]%mod)%mod;
	printf("%d",ans);
	return 0;
}
