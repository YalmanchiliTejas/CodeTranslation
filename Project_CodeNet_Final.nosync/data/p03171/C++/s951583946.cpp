
//Code by: Nikhil Shukla, MMMUT GKP
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define V vector
#define pb push_back
#define all x x.begin(),x.end()
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll t; cin>>t; while(t--)
#define tc1 ll tt=1; while(tt--)
#define fir first
#define sec second
#define mod 1000000007
#define out1(x) cout<<x<<"\n";
#define out2(x,y) cout<<x<<" "<<y<<"\n";
#define debug() cout<<"I am in\n";
#define Vll vector<long long>
#define FOR(i,x,n) for(ll i=x;i<n;i++)
#define RFOR(i,x,n) for(ll i=x;i>=n;i--)
////////////////////////////////////////////////////////////////////////////////////////
/*vector<ll>graph[100001];
vector<ll>temp;
vector<bool>visited(100001,false);
//long long count=0;
void dfs(long long node,ll dp[])
{
        visited[node]=1;
        for(ll i=0;i<graph[node].size();i++)
        {
            if(!visited[graph[node][i]])
            dfs(graph[node][i],dp);
            dp[node]=max(dp[node],1+dp[graph[node][i]]);
        }
}*/

ll dp[3002][3002];
ll visited[3002][3002];
ll a[3002];
ll n;
ll solve(ll i,ll j)
{
    if(visited[i][j])
    return dp[i][j];
    visited[i][j]=1;
    if(i==j)
    return dp[i][j]=a[i];
    return dp[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
}
int main()
{
    fast()
    tc1
    {
        FOR(i,0,3001)
        FOR(j,0,3001)
        visited[i][j]=0;
        cin>>n;
        FOR(i,1,n+1)
        cin>>a[i];
        cout<<solve(1,n)<<"\n";
    }
    
    return 0;
}
