#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
ll dp[3001][3001], pre[3001][3001];

int main(){
    ll n,s;
    cin>>n>>s;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    //dp[i][j] stores sum of left ends of all those subsequences having sum sum j and ending at i
    //pre[i][j] stores sum of all left endpoints having sum j and including only upto i terms
    memset(pre, 0, sizeof(pre));
    for(ll j=0; j<=s; j++){
//        cout<<"With Sum "<<j<<": ";
        for(ll i=0; i<=n; i++){
            if(i==0 || j==0){   // i==0 means no element included
                // j==0 means sum 0
                dp[i][j] = 0;
            }
            else if(j==a[i-1]){
                dp[i][j] = i; //Starting and ending at i
            }else if(j>a[i-1]){
                //Ending at 'i' and sum is equal to j
                dp[i][j] = pre[i-1][j-a[i-1]];
            }else{
                dp[i][j] = 0;
            }
            if(i>0){
                pre[i][j] = pre[i-1][j] + dp[i][j];
                pre[i][j] %= mod;
            }
            dp[i][j] %= mod;
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    ll ans=0;
    for(ll i=1; i<=n; i++){
        ans += (dp[i][s]*(n-i+1))%mod;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}