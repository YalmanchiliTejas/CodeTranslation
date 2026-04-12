#include<bits/stdc++.h>
using namespace std;

long long n,ans,k,l,r;
int main()
{
	cin>>n>>k;
	if (k==0)
	{
		printf("%lld\n",n*n);
		return 0;
	}
	for (int i=k+1;i<=n;i++)
	{
		ans+=(n/i)*(i-k);
		if (n%i!=0)ans+=max(0ll,n-(n-n%i+k-1));
		// cout<<ans<<endl;
	}
	cout<<ans;
}
