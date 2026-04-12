#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll dp[3005][3005]={0};
ll arr[3005];
ll solve(ll start,ll end)
{
	if(start>end)
		return 0;
	else if(start==end){
		dp[start][end]=arr[start];
		return arr[start];
	}
	else if(dp[start][end])
		return dp[start][end];
	
	return dp[start][end]=max(arr[start]-solve(start+1,end),arr[end]-solve(start,end-1));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	cout<<solve(0,n-1)<<endl;
	


}