#include<bits/stdc++.h>
#define ld  double
#define ll long long 
#define pp push
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 1e9
#define f first
#define s second
#define pll pair<ll,ll>
#define vll vector<ll>
#define vi vector<int>
#define mod 1000000007
using namespace std;
ll dp[3007][3007];
ll a[3007];
ll n;
ll solve(ll i,ll j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==j)return dp[i][j]=a[i];
    dp[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
    return dp[i][j];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    cout<<solve(0,n-1);
}