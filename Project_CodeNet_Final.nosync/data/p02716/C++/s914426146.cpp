#include <bits/stdc++.h>
#include <numeric>
#define fast()                        \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define endl "\n"
#define mod 1000000007
#define PI 3.14159265358979323846
#define ff first
#define pb push_back
#define ss second
#define un unordered
#define for0(i, n) for (i = 0; i < n; i++)
#define for1(j, n) for (j = 1; j <= n; j++)
#define ll long long int
#define all(v) v.begin(), v.end()
#define t6 2000010
#define t5 200005
using namespace std;
ll recur(ll arr[],ll i,ll n,ll flag,ll count,pair<ll,ll> **dp){
	if(count==n/2){
		return 0;
	}
	else if(i==n && count!=n/2){
		return -1e17;
	}
	ll ans=0;
	if(dp[count][flag].first==i){
		return dp[count][flag].second;
	}
	if(flag==1){
		ans=recur(arr,i+1,n,1-flag,count,dp);
	}	
	else{
		if((n-i+1)/2==n/2-count){
			ans=(arr[i]+recur(arr,i+1,n,1-flag,count+1,dp));
		}
		else{
			ans=max(arr[i]+recur(arr,i+1,n,1-flag,count+1,dp),recur(arr,i+1,n,flag,count,dp));
		}
	}
	dp[count][flag]={i,ans};
	return ans;
}
void solve(){

	ll n;
	cin>>n;
	ll arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll pre[n+1]={0};
	pre[1]=arr[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-2]+arr[i];
	}
	ll dp[n+1]={0};
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==1){
			dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
		}	
		else{
			dp[i]=max(dp[i-2]+arr[i],pre[i-1]);

		}
	}
	cout<<dp[n]<<endl;



}

int main()
{
	fast()
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++)
	{   //cout<<"Case #"<<i+1<<": ";
		solve();
	}   
	
	return 0;
}