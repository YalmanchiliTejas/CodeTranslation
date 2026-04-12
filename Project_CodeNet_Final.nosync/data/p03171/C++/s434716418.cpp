#include<bits/stdc++.h>
using namespace std;
long long const MAX=3002;
long long dp[MAX][MAX];
void funk()
{long long i,j;
for(i=0;i<MAX;i++)
{for(j=0;j<MAX;j++)
{dp[0][0]=0;}}}
int main()
{long long i,j,n,r,k,p,w,y,sum,m,x;
cin>>n;
long long a[n];
for(i=0;i<n;i++)
{cin>>a[i];}
for(i=0;i<n;i++)
{dp[i][i]=a[i];}
for(i=n-1;i>=0;i--)
{for(j=i+1;j<n;j++)
{dp[i][j]=max(a[j]-dp[i][j-1],a[i]-dp[i+1][j]);}}
cout<<dp[0][n-1];

return 0;}
