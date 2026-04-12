#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>&arr,ll s,ll e,vector<vector<ll>>&dp){
    if(s>e)
        return 0;
    
    if(dp[s][e]!=-1)
        return dp[s][e];
    dp[s][e] = max(arr[s]+min(solve(arr,s+2,e,dp),solve(arr,s+1,e-1,dp)),arr[e]+min(solve(arr,s+1,e-1,dp),solve(arr,s,e-2,dp)));
    
    return dp[s][e];
}
int main() {
	// your code goes here
	ll n;
	cin>>n;
	vector<ll> arr(n);
	ll sum1=0;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    sum1+=arr[i];
	}
	vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
	ll p1 = solve(arr,0,n-1,dp);
	ll p2 = sum1-p1;
	cout<<p1-p2<<endl;
	return 0;
}
