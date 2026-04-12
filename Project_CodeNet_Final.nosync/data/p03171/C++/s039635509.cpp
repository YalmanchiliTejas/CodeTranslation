#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[3001][3001];
long long solve(vector<int>&a,int l,int r)
{
    if(l>r) return dp[l][r]=0;
    if(l==r) return dp[l][r]=a[l];
    if(r==l+1) return dp[l][r]=max(a[l],a[r]);
    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r]=max(a[l]+min(solve(a,l+2,r),solve(a,l+1,r-1)),a[r]+min(solve(a,l+1,r-1),solve(a,l,r-2)));
}
int main()
{
    int n,m,k; cin>>n;
    long long total=0;
    vector<int>a(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {cin>>a[i]; total+=a[i];}
    long long x=solve(a,0,n-1);
    cout<<2*x-total;
//     int dp[n][n]={0};
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(j==i+1)  {dp[i][j]=abs(a[i]-a[j]); continue;}
//             if(dp[i-v]==0) dp[i]=1;
//         }
//     }
//   dp[k]==1?cout<<"First":cout<<"Second"; 
}