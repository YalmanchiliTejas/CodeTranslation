#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long n,s=0;
	cin>>n;
	long long a[n+1],f[n+1],ans=0LL;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		f[i]=s;
	}
	for(int i=1;i<n;i++)
	{
		ans+=((a[i]%1000000007)*\
		((s-f[i])%1000000007))%1000000007;
		ans%=1000000007;
	}
	cout<<ans;
	return 0;
}