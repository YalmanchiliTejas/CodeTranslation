#include <bits/stdc++.h>
#define ff first
#define ss second 
#define MP make _pair
#define PB push_back
#define ll long long
#define pri 1000000007
using namespace std;
void run(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){cin>>a[i];}
	ll z=n%2;
	ll dp[n+1][n+1];
	for(ll i=0;i<n+1;i++){
		for(ll j=0;j<n+1;j++)dp[i][j]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=n-i;j++){
		  if(i%2==z)
		  dp[j][i]=max(dp[j+1][i-1]+a[j],dp[j][i-1]+a[i+j-1]);	
		  else 
		  dp[j][i]=min(dp[j+1][i-1]-a[j],dp[j][i-1]-a[i+j-1]);	
		}
		
	}

	cout<<dp[0][n];
}
int main() {
	run();
	// your code goes here
	return 0;
}