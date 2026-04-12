#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false),cin.tie(0);
#define ll long long
#define inf 0x3f3f3f3f
const int N=2e5+5;
//set<string>b;
//set<string>::iterator it;
const ll mod=1e9+7;
ll a[N];
int main()
{
	IO;
	ll n,i,sum=0,ans=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<n;i++) sum=(sum+a[i])%mod;
	for(i=0;i<n;i++)
	{
		ans=(ans+sum*a[i])%mod;
		sum=((sum-a[i+1])%mod+mod)%mod;
	}
	cout<<ans<<endl;
    return 0;
}