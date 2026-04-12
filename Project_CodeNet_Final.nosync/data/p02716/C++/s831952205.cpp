#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000,mod=1000000007;
ll power(ll a,ll b){
    ll res=1;
    a%=mod;
    while(b){
        if(b&1)
        res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)cin>>arr[i];
        ll dp[n][2];
        for(ll i=0;i<n;i++)for(ll j=0;j<2;j++)dp[i][j]=0;
        //0 i+1/2 1 i+1/2+1
        dp[0][0]=0;dp[0][1]=arr[0];
        dp[1][0]=max(arr[0],arr[1]);dp[1][1]=-inf;
        for(ll i=2;i<n;i++){
            if(i%2==0){
                dp[i][0]=dp[i-1][0];
                dp[i][0]=max(arr[i]+dp[i-2][0],dp[i][0]);
                dp[i][1]=arr[i]+dp[i-2][1];
            }
            else{
                dp[i][0]=dp[i-1][1];
                dp[i][0]=max(dp[i][0],arr[i]+dp[i-2][0]);
                dp[i][1]=-inf;
            }
        }
        cout<<max(dp[n-2][1],dp[n-1][0]);

}
