#include <bits/stdc++.h>
using namespace std;
long long int dp[2][3001][3001];
long long int v[2][3001][3001];
long long int n;
long long int a[3001];
long long int solve(long long int player,long long int s,long long int e)
{
 if(s>e)
 return 0;
 if(v[player][s][e]!=0)
 return dp[player][s][e];
 v[player][s][e]=1;
 if(player==0)
 return dp[player][s][e]=max(solve(1,s+1,e)+a[s],solve(1,s,e-1)+a[e]);
 else
 return dp[player][s][e]=min(solve(0,s+1,e)-a[s],solve(0,s,e-1)-a[e]);
}
int main()
{
    long long int i,j,k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cout<<solve(0,0,n-1);
}