#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll dp[3003][3003];
ll arr[3003];
ll solve(ll l,ll r){
	if(l>r)return 0;
	if(l==r)return arr[l];
	if(dp[l][r]!=-1)return dp[l][r];
	
//	cout<<l<<' '<<r<<'\n';
	
	ll x=arr[l]+min(solve(l+2,r),solve(l+1,r-1));
	ll y=arr[r]+min(solve(l,r-2),solve(l+1,r-1));
	dp[l][r]=max(x,y);
	return dp[l][r];
}

int main(){
	ll n,k;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		
		//cout<<"sun "<<i<<' '<<arr[i]<<' '<<sum<<'\n';
	}
//	cout<<solve(0,n-1)<<' '<<sum<<'\n';
	cout<<2*solve(0,n-1)-sum;
	
}