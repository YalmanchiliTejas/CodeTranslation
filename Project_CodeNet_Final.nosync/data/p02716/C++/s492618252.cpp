/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
const ll MAX=1e5+5;
const ll INF=2e18+10;
const int inf=1e9+10;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(auto &i:a)cin>>i;
    ll dp[n+1];
    ms(dp,0);
    ll sum=a[0];
    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i]=max(dp[i-2]+a[i-1],dp[i-1]);
            sum+=a[i-1];
        }
        else dp[i]=max(dp[i-2]+a[i-1],sum);
    }
    cout<<dp[n]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    return 0;
}