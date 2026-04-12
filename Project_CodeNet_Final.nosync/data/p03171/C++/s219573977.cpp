#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define pb emplace_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(0);

const int N = 3005;
int dp[N][N][2];
int a[N],n;
int solve(int l , int r,int turn)
{
    if(l > r)   return 0;
    if(l == r && turn)  return -a[l];
    if(l==r)          return a[l];
    if(dp[l][r][turn]!=-1)   return dp[l][r][turn];
    ll ans = 0;
    if(turn%2)   ans = min(-a[l]+solve(l+1,r,turn^1),-a[r]+solve(l,r-1,turn^1));
    else
    ans = max(a[l]+solve(l+1,r,turn^1),a[r]+solve(l,r-1,turn^1));
    return dp[l][r][turn] = ans;
}
int32_t main(){
	fast;
    cin >> n;
    for(int i=1 ; i<=n ; i++)   cin >> a[i];
    memset(dp,-1,sizeof(dp));
    int ans = solve(1,n,0);
    cout << ans;
}