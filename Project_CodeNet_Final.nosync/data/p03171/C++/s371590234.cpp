//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 3 * 1e3 + 10;

ll res;
ll a[N], dp[N][N];

void solve(){
    ll n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        dp[i][i] = a[i];
    }
    for(int j = 1; j < n; ++j){
        for(int i = 1; i <= n; ++i){
            if(j + i <= n){
                dp[i][i + j] = max(a[i] - dp[i + 1][i + j], a[i + j] - dp[i][i + j - 1]);
            }
        }
    }
    cout << dp[1][n];
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
// nEro