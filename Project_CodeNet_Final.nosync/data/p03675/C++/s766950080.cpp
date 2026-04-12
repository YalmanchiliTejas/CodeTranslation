#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,l,r;
int a[1000005];

int main()
{
	scanf("%d",&n);
	l=r=n;
	scanf("%d",&a[l]);
	for(i=2;i<=n;++i)
	{
		scanf("%d",&k);
		if(i&1)a[++r]=k;else a[--l]=k;
	}
	if((n&1)==0)for(i=l;i<=r;++i)printf("%d ",a[i]);
	else for(i=r;i>=l;--i)printf("%d ",a[i]);
}