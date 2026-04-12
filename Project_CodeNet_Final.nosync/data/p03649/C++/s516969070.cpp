#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int main()
{
	long long n,a[55],i,sum,num,key,k;
	while(scanf("%lld",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		key=1;sum=0;
		while(key)
		{
			k=1;key=0;
			for(i=2;i<=n;i++)
			{
				if(a[i]>a[k])
				{
					k=i;
				}
			}
			if(a[k]>=n)
			key=1;
			if(key)
			{
				num=a[k]/n;
				sum+=num;
				a[k]=a[k]%n;
				for(i=1;i<=n;i++)
				{
					if(i!=k)
					a[i]+=num;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}