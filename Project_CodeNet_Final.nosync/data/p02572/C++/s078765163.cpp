#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
	
int main(){
	ll n;
	cin>>n;
	ll ar[n];
	for(int i=0;i<n;i++){
	 	cin>>ar[i];
	}
	 
	ll *dp = new ll[n+1]();
	dp[n] = ar[n-1];
	for(int i=n-1;i>0;i--){
	 	dp[i] = (dp[i+1]%mod + ar[i-1]%mod)%mod;
	}
	/*for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}*/
	 
	ll sum = 0;
	
	for(int i=1;i<n;i++){
		ll curr = (ar[i-1]%mod*dp[i+1]%mod)%mod;
		sum = (sum%mod+curr%mod)%mod;	
	}
	cout<<sum%mod;		 
	 	 
	 return 0;
	}
