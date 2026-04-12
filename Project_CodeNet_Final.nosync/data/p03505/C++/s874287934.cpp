#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long LL;
int main()
{
	LL K,A,B;
	scanf("%lld %lld %lld",&K,&A,&B);
	LL sum=A;
	if(sum>=K)
		printf("1\n");
	else
	if(sum<K && B>=A)
		printf("-1\n");
	else
	{
		LL gg;
		LL times=(K-sum)/(A-B);
		if((K-sum)%(A-B)!=0)
			times++;
		gg=times*2+1;
		printf("%lld\n",gg);
	}
	return 0;
 } 