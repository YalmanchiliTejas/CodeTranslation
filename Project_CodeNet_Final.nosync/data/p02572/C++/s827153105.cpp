#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	ll n;cin>>n;
	ll a[n],pSum[n]={0};
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		sum=sum%mod;
		pSum[i]=sum;
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=((a[i]%mod)*(pSum[n-1]-pSum[i])%mod)%mod;
		ans=ans%mod;
	}
	cout<<(ans+mod)%mod;

}