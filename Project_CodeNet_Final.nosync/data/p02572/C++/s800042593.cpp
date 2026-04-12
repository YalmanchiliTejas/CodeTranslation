#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
const int mod=1e9+7;
typedef long long ll;

ll a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll sum=0,ans=0;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		b[i]%=mod;
	}
	for (int i=1;i<=n;i++)
	{
		ll temp=(b[n]+mod-b[i])%mod;
		ans=(ans+temp*a[i])%mod;
	}
	cout<< ans;
	return 0;
} 