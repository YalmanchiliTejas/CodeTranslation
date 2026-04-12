#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,jc[200020],jcv[200020],ans,dp[200020];
char s[200020];
void init()
{
	jc[0]=1;
	for(int i=1;i<=200000;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[200000]=kpow(jc[200000],mod-2);
	for(int i=200000;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
}
inline int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int main()
{
	init();
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	char r=s[1];
	for(int i=1;i<=m;++i)s[i]=s[i]==r?0:1;
	int last=0,mi=0x3f3f3f3f;
	for(int i=1;i<=m;++i)
		if(s[i]==1)
		{
			if(!last)
			{
				if(i&1)mi=min(mi,i);
				else mi=min(mi,i-1);
			}
			else if((i-last-1)&1)mi=min(mi,i-last-1);
			last=i;
		}
	if(!last)
	{
		for(int k=0;k<=n-2-k;++k)add(ans,C(n-2-k,k));
		add(ans,ans);
		for(int k=0;k<=n-1-k;++k)add(ans,C(n-1-k,k));
		printf("%d",ans);
		return 0;
	}
	if(n&1)return printf("0"),0;
	n>>=1;mi=mi+1>>1;
	int tmp=1;dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		if(i-mi-1>=0)add(tmp,mod-dp[i-mi-1]);
		dp[i]=tmp;
		add(tmp,dp[i]);
	}
	for(int i=1;i<=mi;++i)ans=(ans+1ll*dp[n-i]*i)%mod;
	add(ans,ans);
	printf("%d",ans);
	return 0;
}
