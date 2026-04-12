#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long x,y,z,m,n;
	scanf("%lld %lld %lld",&x,&y,&z);
	if(1 <= x && 1 <= y && 1 <= z && 1e5 >= x && 1e5 >= y && 1e5 >= z && y + 2*z <= x)
	{
    m = y + z;
    n = (x-z)/m;
    printf("%lld",n);
    }
    else printf("wrong");
    return 0;

}