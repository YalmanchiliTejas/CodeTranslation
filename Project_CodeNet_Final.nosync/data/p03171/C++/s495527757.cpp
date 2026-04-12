#include<bits/stdc++.h>
#define pi pair<int,int>
#define mk make_pair
#define f(i,n) for(int i=1;i<=n;i++)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define fr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define li long
#define N 1000000
using namespace std;

vector<li> adj(3005);
ll dp[3002][3002][2];

ll dq(int l , int r,int ind)
{
    if(l>r)
        return 0;
    if(dp[l][r][ind]==-1)
    {
        if(ind==0)
        {
            ll left=adj[l]+dq(l+1,r,1);
            ll right=adj[r]+dq(l,r-1,1);
            dp[l][r][ind]=max(left,right);
        }
        else
        {
            ll left=dq(l+1,r,0)-adj[l];
            ll right=dq(l,r-1,0)-adj[r];
            dp[l][r][ind]=min(left,right);
        }
    }
    return dp[l][r][ind];

}



int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    f(i,n)
        cin>>adj[i];
    ll ans=dq(1,n,0);
    cout<<ans;

}
