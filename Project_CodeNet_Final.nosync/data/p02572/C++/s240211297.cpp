#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	lli n,i,sum=0,ans=0;
	cin>>n;
	lli a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		sum=(sum+a[i])%mod;
		ans=(ans%mod+(a[i+1]*sum)%mod)%mod;
//		cout<<sum<<endl;
	}
	cout<<ans;
	return 0;
}
