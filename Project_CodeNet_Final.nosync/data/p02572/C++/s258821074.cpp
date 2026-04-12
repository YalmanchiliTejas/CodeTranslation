#include <bits/stdc++.h> 
using namespace std; 
//#define endl "\n";
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
const long long int mod=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    	cin>>arr[i];
	ll g=arr[n-1];
	ll ans=0;
	for(int i=n-2;i>=0;i--)
	{
		ans=(ans%mod+((arr[i]%mod)*(g%mod))%mod)%mod;
		g=(g%mod+arr[i]%mod)%mod;
	}
	cout<<ans<<endl;
    return 0;
}
