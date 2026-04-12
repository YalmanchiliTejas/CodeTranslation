#include <cstdio>
using namespace std;

int a[1000005],b[1000005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	int	R, L;
	if(n%2==0)
	{

		R=n/2+1, L=R-1;
		for(int i=1;i<=n;i++)
			if(i&1)
				b[R]=a[i], R++;
			else
				b[L]=a[i],L--;
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
	}
	else
	{

		L=n/2+1, R=L+1;
		for(int i=1;i<=n;i++)
			if(i&1)
				b[L]=a[i], L--;
			else
				b[R]=a[i], R++;
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
	}
return 0;
}