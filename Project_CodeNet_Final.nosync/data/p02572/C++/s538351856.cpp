#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define dou  double 
#define endl "\n"

const int mod=1e9+7;

int mulmod(int a,int b) // (a*b)%mod = (a%mod)*(b%mod)%mod
{
	return ((a%mod)*(b%mod))%mod;
}

void solve()
{
	int n,i,j,sum=0,ans=0;
	cin >> n;
	vector<int> v(n);
	for(i=0;i<n;i++)
	{
		cin >> v[i];
		sum = (sum%mod + v[i]%mod)%mod;
	}
	for(i=0;i<n;i++)
	{
		sum = (sum%mod-(v[i]%mod)+mod)%mod;
		ans = (ans%mod + mulmod(v[i],sum))%mod;
	}
	cout << ans << endl;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
}