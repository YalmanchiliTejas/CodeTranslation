#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 1000000006
#define TEMPMOD1 998244353
#define TEMPMOD2 998244352
#define INF 1000000000000000007
#define NEGINF -1000000000000000007
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define plll pair<ll,pll>
#define vpll vector<pll>
using namespace std;
typedef long long int ll;

ll arr1[3010];
ll dp[3010][3010];
ll solve(ll idx1,ll idx2,ll move)
{
    if(dp[idx1][idx2]!=NEGINF)
    {
        return dp[idx1][idx2];
    }
    if(idx1>idx2)
    {
        return 0;
    }
    ll ans;
    if(!move)
    {
        ans=max(solve(idx1+1,idx2,1-move)+arr1[idx1],solve(idx1,idx2-1,1-move)+arr1[idx2]);
    }
    else
    {
        ans=min(solve(idx1+1,idx2,1-move)-arr1[idx1],solve(idx1,idx2-1,1-move)-arr1[idx2]);    
    }
    dp[idx1][idx2]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(ll i=0;i<3010;i++)
    {
        for(ll j=0;j<3010;j++)
        {
            dp[i][j]=NEGINF;
        }
    }
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<solve(0,n-1,0);
    return 0;
}