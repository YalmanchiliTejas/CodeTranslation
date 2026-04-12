#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[3000], n;
    cin >> n;
    vector<vector<long>> dp (n+1, vector<long> (n+1));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int L = n-1; L >= 0; L--) {
        for (int R = L; R < n; R++) {
            dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
        }
    }
    cout << dp[0][n-1];
}
