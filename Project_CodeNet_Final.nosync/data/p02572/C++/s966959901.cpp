#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll mod=1e9+7;
	vector<ll>a(n);
	vector<ll>pre(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			pre[i]=a[i];
			continue;
		}
		pre[i]=a[i]+pre[i-1];
	}
	ll sum=0;
	for(int i=0;i<n-1;i++)
	{
		ll temp=pre[n-1]-pre[i];
		sum+=((a[i]%mod)*(temp%mod))%mod;
	}
	sum%=mod;
	cout<<sum<<endl;
}
		
