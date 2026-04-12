#include <bits/stdc++.h>
#define pb push_back
#define int long long int
#define f(i,a,b) for (int i= a; i <b; ++i)
using namespace std;

int dp[3005][3005];

int solve(int s,int e,int a[])
{
    if(s>e)
        return 0;
    if(dp[s][e]!=-1)
        return dp[s][e];
    int x=a[s]+min(solve(s+2,e,a),solve(s+1,e-1,a));
    int y=a[e]+min(solve(s+1,e-1,a),solve(s,e-2,a));
    return dp[s][e]=max(x,y);
}

signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    int a[n],s=0;
    for(int i=0;i<n;i++)
       {
         cin>>a[i];
         s+=a[i];
       }
    int x=solve(0,n-1,a);
    int y=s-x;
    cout<<x-y;
}

