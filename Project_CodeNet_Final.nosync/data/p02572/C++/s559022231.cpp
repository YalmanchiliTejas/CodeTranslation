#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
#include<queue>
#define MM 1000000007
using namespace std;

int main(void)
{
	int n,i,a[200000];
	long long mul,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	mul=0;	sum=a[0];
	for(i=1;i<n;i++)	{
		mul=mul+(long long)a[i]*sum;
		mul=mul%MM;
		sum=sum+a[i];
		sum=sum%MM;
	}
	printf("%lld\n",mul);
	return 0;
}