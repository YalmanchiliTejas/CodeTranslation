#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,i,x,y;
	cin>>n;
	int a;
	int* b;
	
	b=(int *)malloc(sizeof(int)*n);

	x=n/2;
	if(n%2==0)
	{
		y=1;
	}
	else
	{
		y=-1;
	}

	for(i=0; i<n; i++)
	{
		cin>>a;
		b[x+i*y]=a;
		x+=i*y;
		y*=-1;
	}

	for(i=0;i<n;i++)
	{
		cout<<b[i];
		if(i==n-1)
		{
			cout<<"\n";
		}
		else
		{
			cout<<" ";
		}
	}

	free(b);

	return 0;
}