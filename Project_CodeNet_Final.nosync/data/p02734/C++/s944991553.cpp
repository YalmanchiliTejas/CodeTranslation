#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=3005,mod=998244353;
int dp[N][N],a[N];
int n;
int solve(int idx,int s)
{
    if(s==0) return n-idx+1;
    if(s<0||idx==n) return 0;

    int &ret=dp[idx][s];
    if(~ret) return ret;
    ret=solve(idx+1,s);
    ret=(ret+solve(idx+1,s-a[idx]))%mod;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        ans=(ans+1ll*(i+1)*solve(i+1,s-a[i])%mod)%mod;
    cout<<ans<<endl;
    return 0;
}
