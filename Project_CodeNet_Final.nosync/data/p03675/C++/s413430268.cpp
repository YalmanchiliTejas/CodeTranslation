#include <cstdio>

int a[200050];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n&1)
	{
		for(int i=n;i>=1;i-=2)
			printf("%d ",a[i]);
		for(int i=2;i<=n;i+=2)
			printf("%d ",a[i]);
	}
	else
	{
		for(int i=n;i>=1;i-=2)
			printf("%d ",a[i]);
		for(int i=1;i<=n;i+=2)
			printf("%d ",a[i]);
	}
}
