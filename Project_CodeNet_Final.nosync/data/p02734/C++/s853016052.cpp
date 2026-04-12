#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
const int mod=998244353;
const int INF=1e18;
int n,s;
int a[3005];
int dp[3005][3005][2];
int dfs(int i,int j,int state)
{
    if(j>s)
        return 0;
    int &an=dp[i][j][state];
    if(an!=-1)
        return an;
    if(j==s)
    {
        if(state==1)
            return an=(n-i+1);
        else
            return an=0;
    }
    if(i==n)
    {
        return an=0;
    }
    return an=(dfs(i+1,j,0)+dfs(i+1,j+a[i],1))%mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(i,0,3005)
        f(j,0,3005)
            f(k,0,2)
                dp[i][j][k]=-1;
    cin>>n>>s;
    f(i,0,n)
        cin>>a[i];
    int ans=0;
    f(i,0,n)
    {
        ans=(ans+(i+1)*dfs(i+1,a[i],1))%mod;
    }
    cout<<ans<<'\n';
    return 0;
}