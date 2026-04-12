#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3005,mod=998244353;
ll n,s,a[N],dp[N][N];
ll func(ll idx,ll sum){
    if(sum==0)return n-idx+2;
    if(sum<0 || idx>n)return 0;
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    ll &ans = dp[idx][sum];
    ans = func(idx+1,sum) + func(idx+1,sum-a[idx]);
    ans%=mod;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll ans=0;for(ll i=1;i<=n;i++)ans+=func(i,s),ans%=mod;
    cout<<ans;
}
