#include<stdio.h>

int main()
{
	long long n, K, A, B;
	scanf("%lld %lld %lld", &K, &A, &B);
	if(K<=A)
		n = 1;
	else if(A<=B)
		n = -1;
	else
		n = (K-B)/(A-B);
	if(n>0)
	{
		while(n*A-(n-1)*B<K)
			n++;
		printf("%lld\n", n*2-1);
	}
	else
		printf("-1\n");
	return 0;
} 