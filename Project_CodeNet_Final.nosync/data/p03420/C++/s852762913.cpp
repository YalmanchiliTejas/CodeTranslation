#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,tmp,i;
	long long ans=0;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0)
	{
		printf("%lld\n",(long long)n*n);
		return 0;
	}
	for(i=k+1;i<=n;i++)
	{
		//k~i-1
		tmp=n%i;
		if(tmp>=k&&tmp<i-1)
		{
			ans+=(long long)(tmp-k+1)*((n-k)/i+1)+(long long)(i-1-tmp)*((n-(i-1))/i+1);
		}
		else
			ans+=(long long)(i-k)*((n-k)/i+1);
	//	printf("%d %d\n",i,ans);
	}
	printf("%lld",ans);
	return 0;
}
