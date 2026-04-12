#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MXN = 3e3 + 10;

ll n;
ll A[MXN], dp[MXN][MXN][2];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> A[i];

    for(int i = 1; i <= n; i ++){
        dp[i][i][0] = A[i];
        dp[i][i][1] = -A[i];
    }
    for(int i = 1; i < n; i ++){
        dp[i][i + 1][0] = max(A[i] - A[i + 1], A[i + 1] - A[i]);
        dp[i][i + 1][1] = min(A[i] - A[i + 1], A[i + 1] - A[i]);
    }

    for(int len = 3; len <= n; len ++){
        for(int l = 1, r = len; r <= n; l ++, r ++){
            dp[l][r][0] =  max(dp[l + 1][r][1] + A[l], dp[l][r - 1][1] + A[r]);
            dp[l][r][1] =  min(dp[l + 1][r][0] - A[l], dp[l][r - 1][0] - A[r]);
        }
    }

    cout << dp[1][n][0];
    return 0;
}
//! N.N
