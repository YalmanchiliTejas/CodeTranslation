#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int main()
{
	int n;
	cin>>n;
	long long int a[n];
	long long int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum=(sum%p+a[i]%p)%p;
	}
	long long int pre[n];
	pre[0]=(sum-a[0]+p)%p;
	for(int i=1;i<n;i++)
	{
		pre[i]=(pre[i-1]-a[i]+p)%p;
	}
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans%p+((a[i]%p)*(pre[i]%p))%p)%p;
	}
	cout<<ans<<"\n";
	

}