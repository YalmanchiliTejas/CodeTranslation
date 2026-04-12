#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
#define mod 1000000007
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	int pre[n]={0};
	for(int i=0;i<n;i++)
	{
		pre[i] = (i-1>=0 ? pre[i-1] : 0) + v[i];
		pre[i]%=mod;

	}

	int ans=0;

	for(int i=1;i<n;i++)
	{
		ans+=(v[i]*pre[i-1])%mod;
		ans%=mod;

	}
	cout<<ans<<endl;




}
signed main()

{
	FAST_IO;
	int t = 1;

	// cin>>t;

	while(t--)
	{
		solve();
	}
	
	return 0;
}