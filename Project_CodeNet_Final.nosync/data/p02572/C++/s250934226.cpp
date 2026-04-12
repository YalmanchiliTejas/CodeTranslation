#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;

int main() {
	
	int n;
	cin>>n;
	
	ll arr[n+1];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int sum[n+5];
	sum[n]=0;
	for(int i=n-1;i>=0;i--)
	{
	    sum[i]=(sum[i+1]+arr[i])%mod;
	}
	
	ll ans=0;
	for(int i=0;i<n;i++)
	{
	    ll val=(arr[i]*sum[i+1])%mod;
	    ans=(ans+val)%mod;
	}
	cout<<ans;
}
