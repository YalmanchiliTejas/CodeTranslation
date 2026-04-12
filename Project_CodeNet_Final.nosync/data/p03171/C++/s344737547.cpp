#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i= 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll dp[n][n];
    for(ll i= 0; i < n; i++){
        for(ll j = 0; j < n - i; j++){
                ll k = j + i;
                ll x, y, z;
                if(j + 2 <= k){
                    x = dp[j + 2][k];
                } else x = 0;
                if(j + 1 <= k - 1){
                    y = dp[j + 1][k - 1];
                } else y = 0;
                if(j <= k - 2){
                    z = dp[j][k - 2];
                } else z = 0;
                
    
                dp[j][k] = max(a[j] + min(x, y), a[k] + min(y, z)); 
                
        }
    }
    // for(ll  i= 0; i < n; i++){
    //     for(ll j= 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << 2 * dp[0][n - 1] - sum << endl;
    
}