#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
ll n,a[3333];
ll dp[3005][3005];
ll solve(ll s, ll e)
{
    if(s==e)return a[s];
    if(dp[s][e]!=-1)return dp[s][e];
    return dp[s][e]=max(a[s]-solve(s+1,e) , a[e]-solve(s,e-1));
}
int main()
{
    fast;
    cin>>n;
    memset(dp , -1 , sizeof dp);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<solve(0,n-1);
return 0;
}