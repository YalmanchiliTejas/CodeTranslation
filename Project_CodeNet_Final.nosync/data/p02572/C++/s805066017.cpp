#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
	int t;
	// cin>>t;
	t=1;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		int res=0;
		int mod=1000000007;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int pp[n];
		pp[0]=a[0];
	    for(int i=1;i<n;i++)
	    {
	    	pp[i]=(pp[i-1]+a[i])%mod;
	    }
	    for(int i=0;i<n;i++)
	    {
	    	res=res%mod+(a[i]%mod*(pp[n-1]-pp[i]+mod)%mod)%mod;
	    	res=res%mod;
	    }
	    cout<<res;
	}
}