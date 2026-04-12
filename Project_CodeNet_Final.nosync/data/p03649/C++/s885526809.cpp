#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long LL;
LL h[50+5][2]; 		//第一个倍数，第二个余数 
int main()
{
	LL sum_b=0;
	LL bushu=0; 
	LL N;
	scanf("%lld",&N);
	for(int i=0;i<N;i++) 
	{
		LL num;
		scanf("%lld",&num);
		h[i][0]=num/N;
		h[i][1]=num%N;
		sum_b+=h[i][0]; 
	} 
	while(sum_b!=0)
	{
		LL sum_a=sum_b;
		bushu+=sum_b;
		sum_b=0; 
		 for(int i=0;i<N;i++)
		{
			h[i][1]=h[i][1]+sum_a-h[i][0];
			h[i][0]=h[i][1]/N;
			h[i][1]=h[i][1]%N;
			sum_b+=h[i][0]; 
		} 
		
	} 
	printf("%lld\n",bushu); 
	return 0;

}