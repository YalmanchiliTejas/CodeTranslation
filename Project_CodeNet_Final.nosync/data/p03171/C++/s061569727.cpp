
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;
ll arr[3005];

ll dp[3005][3005];

ll solve(ll i,ll j){
	if(i>j || i>=n || j>=n || i<0 || j<0)return 0;
	//cout<<i<<" "<<j<<endl;
	if(dp[i][j]==-1){
	
		dp[i][j] = max(arr[i]+min(solve(i+2,j),solve(i+1,j-1)),arr[j]+min(solve(i+1,j-1),solve(i,j-2)));	
		
	}
	//s\cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	return dp[i][j];
	
	
	
}

int main(){
	
	cin>>n;
	ll s = 0;
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<n;++i){
	cin>>arr[i];
	s+=arr[i];
    }
    //cout<<s<<endl;
	cout<<2*solve(0,n-1)-s<<endl;
	//cout<<s-2*solve(0,n-1)<<endl;
}