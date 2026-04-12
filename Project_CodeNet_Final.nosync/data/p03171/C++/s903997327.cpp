#include<bits/stdc++.h>
#define ll long long 
using namespace std;
#define w(x) int x; cin>>x; while(x--)
ll int n,k,mod=1e9+7;
ll int a[3001] , dp[3000][3000];
ll int recur(int i , int j)
{
	if(i==j)
		return a[i];
	if(j-i==1)
		return abs(a[i]-a[j]);
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll int ans1=a[i]-a[i+1]+recur(i+2 , j);
	ll int ans2=a[i]-a[j]+recur(i+1 , j-1);
	ll int ans5=min(ans1 , ans2);
	ll int ans3=a[j]-a[i]+recur(i+1 , j-1);
	ll int ans4=a[j]-a[j-1]+recur(i , j-2);
	ll int ans6=min(ans3 , ans4);
	return dp[i][j]=max(ans5 , ans6);
}

int main()
{
	memset(dp , -1 , sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<recur(0 ,n-1 );
}