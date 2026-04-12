#include<bits/stdc++.h>  
using namespace std;
long long int dp[3005][3005];
int vis[3005][3005]={0};
long long int solve(int q,int i,int j,long long int a[])
{
    if(vis[i][j])return dp[i][j];
    if(j<i)return 0;
    vis[i][j]=1;
    long long int ans;
    if(q==0)
        ans=max(a[i]+solve(1,i+1,j,a),a[j]+solve(1,i,j-1,a));
    else
        ans=min(solve(0,i+1,j,a)-a[i],solve(0,i,j-1,a)-a[j]);
    return dp[i][j]=ans;
} 
int main()
{
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(0,0,n-1,a);
}