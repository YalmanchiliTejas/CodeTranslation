#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t,n,sum=0,ans=0,j,s,i,ar[200005];
	cin>>n;
	for(i=0;i<n;i++)cin>>ar[i];
	for(i=0;i<n;i++)
	{
		sum=(sum+ar[i])%1000000007;
	}
	for(i=0;i<n;i++)
	{
		sum=sum-ar[i];
		if(sum<0)sum+=1000000007;
		ans=(ans+(sum*ar[i])%1000000007)%1000000007;
	}
	cout<<ans<<endl;
	return 0;
}