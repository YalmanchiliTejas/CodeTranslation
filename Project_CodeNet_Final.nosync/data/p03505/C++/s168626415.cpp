#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll k,a,b,x;
int main()
{
	scanf("%lld%lld%lld",&k,&a,&b);
	if(k <= a) printf("1");
	else if(a <= b) printf("-1");
	else {
		if((k-a)%(a-b) >= 1) x=1;
		x = ((k-a)/(a-b)+x)*2+1;
		printf("%lld",x);
	}
	printf("\n");
	return 0;
}