#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    long long a,b,c,d;
	while(~scanf("%lld %lld %lld",&a,&b,&c))
	{
		d =(a/(b+c));
		if((b+c)*d+c<=a) printf("%lld\n",d);
		if((b+c)*d+c>a) printf("%lld\n",d-1);
		}
}