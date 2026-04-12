#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	const unsigned int M = 1000000007;
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll sum=0;
	ll ans=0;
	for(ll i=0;i<n-1;i++)
	{
		sum=(sum%M+a[i]%M)%M;
		ans=(ans%M+(sum*(a[i+1])%M)%M)%M;
	}
	cout<<ans%M;

	return 0;
}