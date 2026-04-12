#include <bits/stdc++.h>
using namespace std;
#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define all(x) (x).begin(),(x).end()
#define pb push_back
int dp[3010][3010][2],a[3010],n;
int f(int l,int r,int state)
{
    if(l==r)
    {
        if(state)return -a[l];
        return a[l];
    }
    if(dp[l][r][state]!=-1e18)return dp[l][r][state];
    if(state)return dp[l][r][state]=min(-a[l]+f(l+1,r,1-state),-a[r]+f(l,r-1,1-state));
    return dp[l][r][state]=max(a[l]+f(l+1,r,1-state),a[r]+f(l,r-1,1-state));
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j][0]=dp[i][j][1]=-1e18;
    cout<<f(1,n,0);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("XORQUERY.inp","r",stdin);
    //freopen("XORQUERY.out","w",stdout);
    //int t;cin>>t;while(t--)
    solve();
    return 0;
}
