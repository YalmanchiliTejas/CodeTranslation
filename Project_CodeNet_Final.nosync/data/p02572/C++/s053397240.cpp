#include<bits/stdc++.h>
using namespace std;
#define ll int
#define lli long long int
const ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    lli arr[n+1];
    lli cum[n+1];
    for(ll i=1;i<=n;i++)
    {
    	cin>>arr[i];
	}
	cum[0]=0;
	for(lli i=1;i<=n;i++)
	{
		cum[i]=cum[i-1]+arr[i];
	}
	lli sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum+=(arr[i]*((cum[n]-cum[i])%mod));
		sum%=mod;
	}
	cout<<sum<<endl;
}