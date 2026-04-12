#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum;
ll a[3009];
ll dp[3009][3009][9];
ll bt(int l,int r,int z){
    if(l > r) return 0;
    ll &ret = dp[l][r][z];
    if(ret != -1) return ret;
    ll x = bt(l+1,r,1-z);
    ll y = bt(l,r-1,1-z);
    if(!z){
        x += a[l],y += a[r];
        ret = max(x,y);
    }
    else ret = min(x,y);
    return ret;
}
int main(){
    fast,cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i],sum += a[i];
    }
    memset(dp,-1,sizeof(dp));
    ll x = bt(0,n-1,0);
    ll y = sum - x;
    cout<<x-y<<endl;
}
