#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for (int& x : a) scanf("%d", &x);
    // dp[i][j] la gia tri max X -Y tai doan i..j
    long long dp[n + 1][n + 1];
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
}
