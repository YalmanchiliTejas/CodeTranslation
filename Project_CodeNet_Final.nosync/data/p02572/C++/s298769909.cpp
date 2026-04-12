#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
long long n,a[300006],s,sum=0,sum1=0;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i)
    {
		sum1+=(a[i]*sum);
		sum1%=1000000007;
		sum+=a[i];
		sum%=1000000007;
	}
	/*sort(a+1,a+n);
	for(int i=1;i<=n;++i)
	{
		s=sqrt(a[i])+1;
		for(int j=1;j<=s;++j)
		{
			if(a[j]>s)
			break;
			if(a[i]%a[j]==0&&a[i]!=a[j])
			sum+=a[i];
		}
	}*/
	printf("%lld",sum1%1000000007);
	return 0;
}