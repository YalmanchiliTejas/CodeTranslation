#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,j,n,x,a[100001],p,co[100001],sum;
	while(1)	{
		scanf("%d",&n);
		if(n==0)	break;
		p=0;
		for(i=1;i<=n;i++)	{	
			scanf("%d",&x);
			if(i%2==1)	{
				if(p==0)	{
					a[p]=1;	co[p]=x;
					p++;
				}
				else {
					if(x==co[p-1])	{
						a[p-1]++;
					}
					else {
						a[p]=1;	co[p]=x;
						p++;
					}
				}
			}
			else {
				if(x==co[p-1])	{
					a[p-1]++;
				}
				else {
					if(p<=1)	{
						a[p-1]++;	co[p-1]=x;
					}
					else {
						a[p-2]+=a[p-1]+1;
						p--;
					}
				}
			}
//			for(j=0;j<p;j++)	printf("%d: a=%d co=%d\n",j,a[j],co[j]);
		}
		sum=0;
		for(i=0;i<p;i++)	{
			if(co[i]==0)	sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
