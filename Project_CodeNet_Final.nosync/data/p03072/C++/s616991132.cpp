#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int N,a[20],i,max,H;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	max=a[0];
	for(H=1,i=1;i<N;i++)
	{
		if(a[i]>=max)
		{H++;max=a[i];}
	}
	printf("%d\n",H);
	return 0;
}
