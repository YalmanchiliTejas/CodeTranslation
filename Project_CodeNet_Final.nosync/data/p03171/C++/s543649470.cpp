#include <bits/stdc++.h>
#define ll long long
using namespace std;
//dp[i][j] represents score till now of the playing player
int main() {
    int n;
    cin >> n;
    ll A[n];
    for(ll &x : A) cin >> x;
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int l = n - 1; l >= 0; --l){
        for(int j = l; j < n; ++j){
            if(l == j){
                dp[l][j] = A[l];
                continue;
            }
            dp[l][j] = max(A[l] - dp[l + 1][j], A[j] - dp[l][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}