#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long ll;
int a[100000+100];
int b[100000+100];
ll my_max(ll c,ll d)
{
	return c>d?c:d;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ls=n/2;
	ll sum=abs(a[n-1]-a[0]);
	for(int i=1;i<ls;i++)
	{
		ll e,b,c,d;
		e=a[i-1];
		b=a[i];
		d=a[n-i];
		c=a[n-1-i];
		sum+=(ll)(abs(c-e)+abs(d-b));
	} 
	if(n%2==1)
	{
		int z=n/2;
		sum+=my_max(abs(a[z]-a[z+1]),abs(a[z]-a[z-1]));	
	}
	printf("%lld\n",sum);
	return 0;
 } 