#include<bits/stdc++.h>
using namespace std;
long long k,a,b;
int main()
{
	scanf("%lld%lld%lld",&k,&a,&b);
	if(k<=a) return printf("1\n"),0;
	if(a<=b) return printf("-1\n"),0;
	return printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1),0;
}