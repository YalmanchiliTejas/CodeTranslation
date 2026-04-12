#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp(3003,vector<ll>(3003,-1));
int n;
vector<int> v(3003);
ll solve(int i,int j,int t)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    ll ans;
    if(t)
    {
        ans=0;
       ans = max(ans,v[i]+solve(i+1,j,!t));
       ans = max(ans,v[j]+solve(i,j-1,!t));
    }
    else
    {
        ans = LONG_MAX;
        ans = min(ans,solve(i+1,j,!t));
        ans = min(ans,solve(i,j-1,!t));
    }
    return dp[i][j] = ans;
}
int main() {
    int n;
    cin>>n;
    ll tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        tot+=v[i];
    }
    ll X = solve(0,n-1,1);
    ll res = 2*X-tot;
    cout<<res;
}
