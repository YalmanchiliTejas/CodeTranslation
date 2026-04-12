#include<cstdio>
#include<algorithm> 
int n,k;
long long ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int x=n/i,r=n%i;
		ans=ans+1ll*x*std::max(0,i-k)+std::max(0,r-k+1);
		if (k==0) --ans;
	}
	printf("%lld\n",ans);
}