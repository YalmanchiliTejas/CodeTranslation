#include<cstdio>
#include<iostream>
#define S 100

int main(void)
{
	int a[S];
	int i;
	int n,max,min,sum=0;
	
	for(;;)
	{
		max=0, min=1000,sum=0;
		
		scanf("%d",&n);
		if(n==0) break;
		
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(i=0; i<n; i++)
		{
			if(max<a[i]) max=a[i];
			if(min>a[i]) min=a[i];
		}
		
		for(i=0; i<n; i++)
		{
			sum+=a[i];
		}
		
		sum=sum-max-min;
		printf("%d\n",sum/(n-2));
	}
	
	return 0;
}