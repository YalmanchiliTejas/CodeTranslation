#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
#include<cmath>
#include<iterator>
typedef long long ll;
using namespace std;
#define rep(x, y)   for (ll i = x; i <= y; i ++)
#define repi(x, y)  for (ll i = x; i >= y; i --)
priority_queue< ll > cancel;
ll arr[200005];
ll brr[200005];
ll dp[3005][3005];
ll maximise(ll start,ll end)
{
    if(start==end)
    {
        dp[start][end]=arr[end];
        return dp[start][end];
    }
    else  if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    else
    {
        dp[start][end]=max(arr[start]-maximise(start+1,end),arr[end]-maximise(start,end-1));
        return dp[start][end];
    }
}
int main()
{
    ll test=1;
    // cin>>test;
    for(ll z=0;z<test;z++)
    {
        ll n,k;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        } 
        cout<<maximise(0,n-1)<<endl;
    }
}