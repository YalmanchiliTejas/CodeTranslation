#include <iostream>
#include <cstdio>
using namespace std;

long long a,b,c;
bool flag=false;

int main()
{
	scanf("%lld %lld %lld",&a,&b,&c);
	if((a*100+10*b+c)%4==0)flag=true;
	if(flag==true)puts("YES");
	else puts("NO");
	return 0;
}