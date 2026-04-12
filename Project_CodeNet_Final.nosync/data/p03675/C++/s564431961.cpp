#include<stdio.h>
long long a[1000000],b[1000000],n;


int main()
{
	long long x=0,temp,s;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n%2)
	{
		for(long long i=n-1;i>=0;i--)
		{
			if(i%2==0)printf("%lld ",a[i]);
		}
		for(long long i=0;i<n;i++)
		{
			if(i%2==1)printf("%lld ",a[i]);
		}			
	}
	else
	{
		for(long long i=n-1;i>=0;i--)
		{
			if(i%2) printf("%lld ",a[i]);
		}
		for(long long i=0;i<n;i++)
		{
			if(i%2==0) printf("%lld ",a[i]); 
		}
	}
	return 0;
}