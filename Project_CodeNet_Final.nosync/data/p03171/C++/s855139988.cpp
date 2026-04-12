#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n;
    cin >> n;
    ll ar[n];
    for(ll i = 0;i < n;i++) cin >> ar[i];
    ll dp[n][n];
    memset(dp,0,sizeof dp);
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j + i < n;j++){
            if(i==0){
                dp[j][j] = ar[j];
                continue;
            }
            dp[j][j+i] = max(ar[j]-dp[j+1][j+i],ar[j+i]-dp[j][j+i-1]);
        }
    }
    cout<<dp[0][n-1];
}