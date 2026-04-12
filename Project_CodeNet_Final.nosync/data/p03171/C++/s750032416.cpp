#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll recursion(ll arr[],ll i,ll j,vector<vector<ll> > &dp)
{

	if(i>j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(i==j)
	{
		return dp[i][j]=arr[i];
	}
	else if(i+1==j)
	{
		return dp[i][j]=max(arr[i],arr[j]);
	}
	else
	{
		return dp[i][j]=max(arr[i]+min(recursion(arr,i+1,j-1,dp), recursion(arr,i+2,j,dp)) , arr[j] + min(recursion (arr , i , j -2,dp), recursion (arr , i +1, j -1,dp) ));
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll N;
	cin>>N;
	ll arr[N];
	ll sum=0;
	for(auto &it:arr)
	{
		cin>>it;
	}
	for(auto it:arr)
	{
		sum+=it;
	}
	vector<vector<ll> > dp(N,vector<ll> (N,-1) );
	ll score=recursion(arr,0,N-1,dp);
	cout<<2*score-sum;

}