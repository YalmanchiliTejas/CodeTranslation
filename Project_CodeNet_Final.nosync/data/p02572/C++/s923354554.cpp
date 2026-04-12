#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long a[200001];
int main()
{
	int n;cin>>n;
	long long sum=0,ans=0,qzh=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum=(sum+a[i])%mod;
	for(int i=1;i<=n;i++)
		qzh=(qzh+a[i])%mod,ans=(ans+(sum-qzh)%mod*a[i]%mod)%mod;
	cout<<((ans%mod)+mod)%mod;
	return 0;
}