//Harjot Singh Student NIT JALANDHAR	

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
ll dp[3001][3001][2];

ll solve(ll *arr,int i,int j,int state)
{

	if(i>j) return 0;

	if(dp[i][j][state]!=-1) return dp[i][j][state];

	if(state==1)
		return dp[i][j][state]=max(arr[i]+solve(arr,i+1,j,0),arr[j]+solve(arr,i,j-1,0));
	else
		return 	dp[i][j][state]=min(solve(arr,i+1,j,1),solve(arr,i,j-1,1));

}

int main()
{
    
    int  n;
    cin>>n;
    ll arr[n+1];ll sum=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>arr[i];sum+=arr[i];
    }
    memset(dp,-1,sizeof(dp));
    ll x=solve(arr,1,n,1);
    ll y=sum-x;

    cout<<x-y<<endl;


	return 0;
}