#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3001][2];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &i: arr)
        cin >> i ;
    for (int i=0; i<n; i++)
        for (int r = 0, c = i;  c<n ; r++, c++){
            if (i==0)
                dp[r][c][0] = arr[r];
            else if (i==1)
                dp[r][c][0] = max(arr[r], arr[c]), dp[r][c][1] = min(arr[r], arr[c]);
            else {
                long long first = arr[c]+dp[r][c-1][1], second = arr[r]+dp[r+1][c][1];
                if (first==second)
                    dp[r][c][0] = first, dp[r][c][1] = max(dp[r+1][c][0], dp[r][c-1][0]);
                else if (first>second)
                    dp[r][c][0] = first, dp[r][c][1] = dp[r][c-1][0];
                else dp[r][c][0] = second, dp[r][c][1] = dp[r+1][c][0];
            }
        }
    cout << dp[0][n-1][0]-dp[0][n-1][1] << "\n";
}