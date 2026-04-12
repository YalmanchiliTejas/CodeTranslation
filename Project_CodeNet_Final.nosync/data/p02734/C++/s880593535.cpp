#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll dp[3030][3030][3];
int a[3030];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i,n) cin >> a[i];
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,k+1){
            (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
            if(j + a[i] <= k){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
            }
        }
    }
    cout << dp[n][k][2] << endl;
}