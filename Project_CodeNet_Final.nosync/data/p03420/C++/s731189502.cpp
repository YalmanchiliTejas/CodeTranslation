#include<cstdio>
#include<iostream>
using namespace std;

long long n,k;

int main()
{
	cin>>n>>k;
	long long ans=0;
	for(int i=k+1;i<=n;i++)
		ans+=n/i*(i-k)+(n%i!=0)*max(n-n/i*i-k+(k!=0),0ll);
	cout<<ans;
}