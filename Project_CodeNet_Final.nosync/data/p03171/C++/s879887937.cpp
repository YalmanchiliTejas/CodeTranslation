#include<bits/stdc++.h>

using namespace std;

long long n, k, a[3005], dp[3005][3005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int l = n - 1; l >= 0; l--){
        for (int r = l; r < n; r++){
            dp[l][r] = l == r? a[l] : max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}