#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin>>n;
	long long int i;
	long long int a[n];
	long long int ans=0;
	long long int mod=1000000007;
	for(i=0;i<n;i++)
		cin>>a[i];
	long long int ps[n];
	ps[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		ps[i]=ps[i+1]+a[i+1];
		if(ps[i]>=mod)
			ps[i]-=mod;
	}
	for(i=0;i<n;i++)
	{
		ans+=ps[i]*a[i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}