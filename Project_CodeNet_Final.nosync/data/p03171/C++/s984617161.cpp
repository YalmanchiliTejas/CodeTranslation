/**************************************************************************
Coded by: Saba Karimi(_VINTAGE)
Institution: AIT PUNE
***************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back 
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define ld long double
#define int long long int 
#define F first 
#define S second
/**************************************************************************/
const int N = 3e3+2;
int dp[N][N][2];
int a[N];
int n;
int solve(int l,int r,int chance)
{
    if(l>r || l>n || r<1)
        return 0;
    if(dp[l][r][chance]!=-1)
        return dp[l][r][chance];
    if(chance == 0)
    {
        int ans1 = a[l]+solve(l+1,r,chance^1);
        int ans2 = a[r]+solve(l,r-1,chance^1);
        dp[l][r][chance] = max(ans1,ans2);
    }
    else
    {
        int ans1 = solve(l+1,r,chance^1)-a[l];
        int ans2 = solve(l,r-1,chance^1)-a[r];
        dp[l][r][chance] = min(ans1,ans2);
    }
    return dp[l][r][chance];
}
signed main()
{
    fast;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n,0);
}