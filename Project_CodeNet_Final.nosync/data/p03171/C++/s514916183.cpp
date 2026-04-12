#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int a[3300];
long dp[3300][3300];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int l = 0; l + i <= n; l++){
            int r = l + i;
            if(i % 2 == n % 2) dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            else dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
        }
    }
    cout << dp[0][n] << endl;
}