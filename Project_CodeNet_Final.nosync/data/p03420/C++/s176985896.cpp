#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long ans,n,k;
long long maxx(long long a,long long b)
{
	if(a>b)  return a;
	else     return b;
}
int main()
{
	cin>>n>>k;
	n++;
	for(long long i=k+1;i<n;i++)//1---n-1
	{
		long long x=i-k;
		ans+=n/i*x+maxx(0,n-n/i*i-k);
	} 
	printf("%lld\n",ans-(!k)*(n-1));
	return 0;
}