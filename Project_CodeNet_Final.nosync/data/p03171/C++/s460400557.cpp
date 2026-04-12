#include<bits/stdc++.h>
#include<stdio.h>
#define ll  long long int
#define M 300002
#define N 1000000000000000003
#define endl "\n"
using namespace std;
////////////////////////// data structures : priority queue, deque ,set , multiset, maps...........etc.........;;;;;;;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll dp[3003][3004]={0};
    ll n;cin>>n;
    ll arr[3005]={0};
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];dp[i][i]=arr[i];
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<=n&&j+i<=n;j++)
        {
            dp[j][i+j]=max(dp[j][j]-dp[j+1][i+j],dp[i+j][i+j]-dp[j][i+j-1]);
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
