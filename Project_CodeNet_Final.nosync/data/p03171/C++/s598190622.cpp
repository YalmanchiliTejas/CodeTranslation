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
int dp[N][N];
int a[N];
int n;
int solve(int l,int r)
{
    if(l>r || l>n || r<1)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    int ans1 = a[l]-solve(l+1,r);
    int ans2 = a[r]-solve(l,r-1);
    dp[l][r] = max(ans1,ans2);
    return dp[l][r];
}
signed main()
{
    fast;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n);
}