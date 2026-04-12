#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);   
	ll n,a[200009],m,k,ans=0,fl=0,mod=1000000007,b[200009];
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		b[i]=b[i]+b[i-1];
		// cout<<b[i]<<" ";
	}
	for(int i=0;i<n-1;i++)
	{
		ll temp=(b[n-1]-b[i])%mod;
		ll te=(a[i]%mod*temp%mod)%mod;
		// cout<<(100000000000000%mod*1000000000)%mod<<endl;
		ans=(ans+te)%mod;
		// cout<<ans<<" "<<te<<" "<<temp<<endl;
	}
	cout<<ans<<endl;
	return 0;
}