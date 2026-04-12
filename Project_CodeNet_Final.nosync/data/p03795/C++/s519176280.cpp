#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	long long n,k;
	long long ans=0;
	scanf("%lld",&n);
	ans+=800*n-n/15*200;
	cout<<ans<<"\n";
	return 0;
}