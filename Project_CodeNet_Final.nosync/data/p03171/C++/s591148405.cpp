#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=3005;
ll mod=1e9+7;
ll a[N];
ll dp[N][N];
ll n;
ll helper(int start,int end)
{
	if(start>end)
	return 0;
	if(start==end)
	return a[start];
	if(start==end-1)
	return max(a[start],a[end]);
	
	if(dp[start][end]!=-1)
	return dp[start][end];
	ll x=helper(start+2,end);
	ll y=helper(start+1,end-1);
	ll z=helper(start,end-2);
	
	return dp[start][end]=max(a[start]+min(x,y),a[end]+min(y,z));
	
	
}
int main()
{
    memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	ll x=helper(0,n-1);
	ll sum=0;
	for(int i=0;i<n;i++)
	sum+=a[i];
	ll y=sum-x;
	cout<<x-y<<endl;
	
	return 0;
}