#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll min(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}

int main() {
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll dp[n][n];
    for(ll k=0;k<n;k++){
        for(ll i=0;i<=n-1-k;i++){
            if(k==0){
                dp[i][i+k]=a[i];
            }else{
                dp[i][i+k]=max(a[i]-dp[i+1][i+k],a[i+k]-dp[i][i+k-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}
