#include <bits/stdc++.h>
using namespace std;
long long a[60],p[60];
long long f(long long n,long long x)
{
    if(n==0)
    {
        if(x<=0)
			return 0;
		return 1;
	}
    else if(x<=1+a[n-1])
		return f(n-1,x-1);
    return p[n-1]+1+f(n-1,x-2-a[n-1]);
}
int main()
{
	int i; 
	long long n,x;
	scanf("%lld %lld",&n,&x);
	a[0]=p[0]=1;
	for(i=1;i<n;i++)
	{
		a[i]=a[i-1]*2+3;
		p[i]=p[i-1]*2+1;
	}
	printf("%lld",f(n,x));
	return 0;
}