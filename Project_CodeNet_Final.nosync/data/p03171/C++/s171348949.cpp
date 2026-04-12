#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long dp[n + 2][n + 2];
    vector<long long>v(n + 2), cum(n + 2);
    cum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        cum[i] = cum[i - 1] + v[i];
        dp[i][i] = v[i];
    }
    for(int i = 2; i <= n; i++){
        for(int l = 1; l + i - 1 <= n; l++){
            int r = l + i - 1;
            long long x = v[l] + cum[r] - cum[l] - dp[l + 1][r];
            long long y = v[r] + cum[r - 1] - cum[l - 1] - dp[l][r - 1];
            dp[l][r] = max(x, y);
        }
    }
    cout << 2*dp[1][n] - cum[n];
    return 0;
}