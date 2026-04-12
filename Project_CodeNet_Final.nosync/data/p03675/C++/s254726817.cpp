#include<cstdio>
using namespace std;
int i,n,a[200010];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d",a[n]);
	for (i=n-2;i>=1;i-=2) printf(" %d",a[i]);
	if (n%2==1)
	{
		for (i=2;i<=n;i+=2) printf(" %d",a[i]);	
	}
	else
	{
		for (i=1;i<=n;i+=2) printf(" %d",a[i]);	
	}
	printf("\n");
}