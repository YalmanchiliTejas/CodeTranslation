#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define endl '\n'
#define N 4005
ll a[N],dp[N][N],n,k;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n-i+1;j++){
            ll e=i+j-1;
            ll x=0,y=0,z=0;
            if(j+2<=e)x=dp[ll(j+2)][ll(e)];
            if(j+1<=e-1)y=dp[ll(j+1)][ll(e-1)];
            if(j<=e-2)z=dp[ll(j)][ll(e-2)];
            dp[j][e]=max(a[j]+min(x,y),a[e]+min(y,z));
        }
    }
    ll rem=sum-dp[1][n];
    cout<<dp[1][n]-rem<<endl;
return 0;
}
