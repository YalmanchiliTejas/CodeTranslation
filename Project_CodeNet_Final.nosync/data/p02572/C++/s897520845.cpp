#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main() {
	// your code goes here
	
	//long double d,t,s;
	ll n;
	cin>>n;
	ll mod=1000000007;
	
	vector<ll> res(n),sumation(n,0);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
	    cin>>res[i];
	    
	  // sumation[i]=(sum+res[i])%mod;
	}
	
	int k=n-1;
	for(int i=1;i<=n;i++)
	{
	    sumation[i]+=(sumation[i-1]+res[k])%mod;
	    k--;
	}
	
	k=n-1;
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{
	    
	    ans+=(sumation[k]*res[i])%mod;
	    k--;
	    ans=ans%mod;
	}
	
	cout<<ans%mod;
	return 0;
}
