#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	    cin>>a[i];
	ll arr[n+1];
	for(ll i=0;i<=n;i++)
	   arr[i]=0;
	for(ll i=n-1;i>=1;i--)
	{
		arr[i]=(arr[i+1]+a[i])%m;
	}
	ll c=0;
	for(ll i=0;i<n-1;i++)
	{
		c=(c+(a[i]*arr[i+1])%m)%m;
	}
	cout<<c<<endl;
	return 0;
}