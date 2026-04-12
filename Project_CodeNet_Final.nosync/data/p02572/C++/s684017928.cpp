#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[1000000];
long long mod=1000000007;
int main()
{
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum-a[i];
		ans=ans%mod+(sum%mod)*(a[i]%mod)%mod;
		ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}