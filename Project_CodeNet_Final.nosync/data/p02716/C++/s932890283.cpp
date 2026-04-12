#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N],prfx[N],dp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    prfx[1]=a[1];
    for(ll i=3;i<=n;i+=2)prfx[i]=prfx[i-2]+a[i];
    for(ll i=2;i<=n;i++){
        if(i&1)dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else dp[i]=max(prfx[i-1],a[i]+dp[i-2]);
    }
    cout<<dp[n];
}
