#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3005;
ll dp[N][N][2],a[N],n;
ll solve(ll l,ll r,ll turn){
    if(l>r)return 0;
    if(dp[l][r][turn]!=-1)return dp[l][r][turn];
    ll &ans=dp[l][r][turn];
    ll v1 = solve(l+1,r,1-turn);
    ll v2 = solve(l,r-1,1-turn);
    if(turn==0)ans=max(v1+a[l] , v2+a[r]);
    else ans=min(v1-a[l] , v2-a[r]);
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n,0);
}