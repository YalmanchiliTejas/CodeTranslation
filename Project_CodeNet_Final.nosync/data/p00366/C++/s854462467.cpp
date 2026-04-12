#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
    int n,i,t[100000],j,p,x,sum,ya[50000];
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&t[i]);
	sort(t,t+n,greater<int>());
	p=0;
	for(i=1;i*i<t[0];i++)	{
		if(t[0]%i==0)	{
			ya[p]=t[0]/i;
			ya[p+1]=i;
			p+=2;
		}
	}
	if(i*i==t[0])	{
		ya[p]=i;	p++;
	}
	sort(ya,ya+p,greater<int>() );
	sum=0;
	for(i=1;i<n;i++)	{
		for(j=0;j<p;j++)	{
			if(t[i]>ya[j])	break;
		}
//		printf("%d %d \n",t[i],ya[j]);
		j--;
		sum+=ya[j]-t[i];
	}
    printf("%d\n",sum);
    return 0;
}
