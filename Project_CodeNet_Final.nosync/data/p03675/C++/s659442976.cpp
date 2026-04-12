#include <cstdio>

int g[300000];
int i,n;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&g[i]);
	for (i=n;i>0;i=i-2)
		printf("%d ",g[i]);
	i=1-i;
	for (;i<=n;i=i+2)
		printf("%d ",g[i]);
	return 0;
}