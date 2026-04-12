#include<bits/stdc++.h>
#define ll long long
#define N 3005
#define M 998244353
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
ll n,s;
ll a[N];
ll dp[N][N];
ll run(int idx,int now)
{
    if(now==s)
    {
        return n-idx+1;
    }
    if(idx==n)
    {
        return 0;
    }
    if(dp[idx][now]!=-1)
        return dp[idx][now];
    //not taking
    ll ans=0;
    ans+=run(idx+1,now);
    ans%=M;
    // taking
    ll age=idx+1;
    if(now+a[idx]<=s&&now==0)
        ans+=(age*run(idx+1,now+a[idx]))%M;
    else if(now+a[idx]<=s&&now!=0)
        ans+=(run(idx+1,now+a[idx]))%M;
    ans%=M;
    return dp[idx][now]=ans;
}

main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<run(0,0);

}
