#include<stdio.h>
int main()
{
	int n,k=0,a[25],max=0,d=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=1;j<n;j++)
	{
		int i;
		for(i=0;i<j;i++)
		{
			if(a[i]<=a[j])
		{
			k++;
		}
	    }
		if(k==i)
		{
			d++;
			k=0;
		}
		else k=0;
		
	}
	printf("%d",d+1);
	return 0;
}