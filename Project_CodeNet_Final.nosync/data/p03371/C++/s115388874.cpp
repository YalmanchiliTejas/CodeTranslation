#include "bits/stdc++.h"
#define INF 0x7fffffff
using namespace std;
vector<int> a; 
int main()
{
	int a,b,c,x,y;
	long long sum=0;
	long long allc;
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	if(c*2<=a+b)
	{
		if(x>y)
		{
			sum+=c*2*y;
			sum+=a*(x-y);
		}
		else
		{
			sum+=c*2*x;
			sum+=b*(y-x);
		}
	} 
	else
	{
		sum+=a*x+b*y;
	}
	allc=max(x,y)*2*c;
	sum=min(sum,allc);
	printf("%lld\n",sum);
	return 0;
}