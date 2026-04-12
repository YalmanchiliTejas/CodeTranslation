#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long

ll dp[3002][3002];
ll solve(ll a[],ll i , ll j,ll n)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll buffer=i+n-1-j;
    if(buffer&1)
    {
        return dp[i][j]=min(-a[i]+solve(a,i+1,j,n),-a[j]+solve(a,i,j-1,n));
    }
    else {
        return dp[i][j]=max(a[i]+solve(a,i+1,j,n) , a[j]+solve(a,i,j-1,n));
    }
}

void test_case()
{
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a,0,n-1,n);
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
