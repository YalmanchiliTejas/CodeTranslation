/*
 
 * This code is written by Sanskar Agarwal
 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

#define ll long long
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define VPLL vector<PLL>
#define VPII vector<PII>
#define PQ priority_queue<PLL,VPLL, greater<PLL> > 
#define PQI priority_queue<PII,VPII,greater<PII> >
#define S second
#define F first
#define PB push_back

ll a[3000];
ll dp[3000][3000][2];

ll solve(ll x,ll y,ll ch)
{
    if(x==y) {
        if(ch==0)
            return dp[x][y][ch]=-a[x];
        else
            return dp[x][y][ch]=a[x];
    }
    if(dp[x][y][ch]!=-1)
        return dp[x][y][ch];

    if(ch==0)
        return dp[x][y][ch]=min(solve(x+1,y,1)-a[x],solve(x,y-1,1)-a[y]);
    else
        return dp[x][y][ch]=max(solve(x+1,y,0)+a[x],solve(x,y-1,0)+a[y]);
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    
    memset(dp,-1,sizeof dp);
    cout << solve(0,n-1,1);


    return 0;
}