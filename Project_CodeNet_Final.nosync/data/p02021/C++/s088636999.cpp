#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a,i,sum,x,mi;
	scanf("%d",&n);
	sum=0;	mi=999;
	for(i=1;i<=n;i++)	{
		scanf("%d",&a);
		sum+=a;
		x=sum/i;
		mi=min(mi,x);
	}
	printf("%d\n",mi);
	return 0;
}
