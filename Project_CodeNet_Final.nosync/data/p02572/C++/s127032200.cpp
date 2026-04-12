#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int a[maxn];
ll sum[maxn];
const int mod=1e9+7;

int main()
{
	int n;
	cin>>n;
	for( int i=1;i<=n;i++ ) cin>>a[i];
	
	for( int i=n;i>=1;i-- ) sum[i]=(sum[i+1]+a[i])%mod;
	
	ll res=0;
	for( int i=1;i<=n;i++ )
	{
		res=(res+ 1ll*a[i]*sum[i+1]%mod )%mod; 
	}
	cout<<res;
}