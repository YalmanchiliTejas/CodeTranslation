#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long check(long long k,long long a,long long b)
{
	if((k-a)%(a-b)>=1)
	{
		n=1;
	}
	return ((k-a)/(a-b)+n)*2+1;
}
int main()
{
	ios::sync_with_stdio(false);
	long long k,a,b,h=0;
	cin>>k>>a>>b;
	if(k<=a)
	{
		cout<<1<<"\n";
		return 0;
	}
	if(b>=a)
	{
		cout<<-1<<"\n";
		return 0;
	}
	cout<<check(k,a,b)<<"\n";
}