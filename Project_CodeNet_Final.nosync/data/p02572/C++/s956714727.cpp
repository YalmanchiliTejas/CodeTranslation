#include<bits/stdc++.h>
using namespace std;
int main()
{

	// #ifndef HAPHAZARD_CODE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

		int n; cin>>n;
		long long int a[n],i,sum=0,ans=0;
		int mod= 1000000007;

		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}

		for(i=0;i<n;i++)
		{
			sum=sum-a[i];
			ans+=(sum%mod * a[i]%mod)%mod;
		}

		ans=ans%mod;

		cout<<ans<<endl;
	return 0;
}

