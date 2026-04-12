#include<cstdio>
#include<cstdlib>
#define rnt register int
using namespace std;
int d[100001];
int n,x;
int main()
{
	scanf("%d",&n);
	for(rnt i=0;i<100001;i=-~i)
		d[i]=-1;
	for(rnt i=0;i<n;i=-~i)
	{
		scanf("%d",&x);
		for(rnt j=0;;j=-~j)
			if(x>d[j])
			{
				d[j]=x;
				break;
			}
	}
	for(rnt i=0;i<=n;i++)
		if(d[i]==-1)
		{
			printf("%d\n",i);
			return 0; 
		}
}