#include<cstdio>
using namespace std;
#define maxn 200100
int a[2*maxn];
int main()
{
	int n,x,h=maxn,t=maxn;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i&1) a[t++]=x;
		else a[--h]=x;
	}
	if(n&1)
	{
		for(int i=t-1;i>=h;i--) printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		for(int i=h;i<t;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}