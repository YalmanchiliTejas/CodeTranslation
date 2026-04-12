#include <stdio.h>
using namespace std;
int main()
{
	int n,x,y=0,c=0;
	scanf("%d",&n);
	x=n*800;
	while(n>=15)
	{
		n-=15;
		c++;
	}
	y=c*200;
	printf("%d",x-y);
}