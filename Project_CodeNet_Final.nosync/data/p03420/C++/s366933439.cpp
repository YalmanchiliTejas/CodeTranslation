#include<stdio.h>
int main()
{
	long long n,k,sum,b,i;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		if(k==0)
		sum=n*n;
		else
		{
			sum=0;
			for(i=k+1;i<=n;i++)
			{
				sum+=(n/i)*(i-k);
				if(n%i>=k)
				sum+=n%i-k+1;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}