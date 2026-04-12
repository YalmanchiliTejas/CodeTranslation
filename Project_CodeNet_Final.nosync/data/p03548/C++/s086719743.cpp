#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long x,y,z,i=0;
	cin>>x>>y>>z;
	while(i*y+(i+1)*z<=x)
	{
		i++;
	}
	printf("%lld\n",i-1);
}
	