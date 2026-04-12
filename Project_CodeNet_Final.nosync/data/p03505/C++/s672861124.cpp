#include<bits/stdc++.h>
using namespace std;
long long int b,z,m,n;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&b);
	if(m>=n)
	{
		printf("1\n");
		return 0;
	}
	if(m<=b)
	{
		printf("-1\n");
		return 0;
	}
	else if((n-m)%(m-b)>=1)
		z=1;
	printf("%lld\n",((n-m)/(m-b)+z)*2+1);
    return 0;
}