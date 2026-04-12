#include<cstdio>
#define int long long
int id[100001],x,m;
long long n;
signed main()
{
	scanf("%lld%lld%lld",&n,&x,&m);
	x%=m;
	long long i,lp=0;
	long long ans=0,smlp=0;
	for(i=x;!id[i];i=i*i%m)
		if(!id[i])
			id[i]=++lp;
	lp-=(id[i]-1);
	for(int j=x;j!=i;j=j*j%m)
		if(j!=i)
			ans+=j;
	smlp=i%m;
	int j;
	for(j=i*i%m;j!=i;j=j*j%m)
		if(j!=i)
			smlp+=j;
	ans+=(n-id[i]+1)/lp*smlp;
	int k=j;
	for(int dd=1;dd<=(n-id[i]+1)%lp;++dd,k=k*k%m)
		ans+=k;
	printf("%lld",ans);
}