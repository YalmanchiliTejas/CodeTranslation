#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nn 3003
int dp[nn][nn][2];
int solve(int *arr, int n, int i, int j, int turn) {
    if (i > j)
        return 0;
    if (dp[i][j][turn] == -1) {
        int a1 = arr[i] + solve(arr, n, i + 1, j, !turn);
        int a2 = arr[j] + solve(arr, n, i, j - 1, !turn);
        if(turn == 0){
         dp[i][j][turn] =max(a1,a2);
        }
        else{
            dp[i][j][turn] = min(a1-arr[i],a2-arr[j]);
        }
    }
    return dp[i][j][turn];
}
main() {
    int n;
    cin >> n;
    int i;
    int arr[n];
    int sum = 0;
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int s1 = solve(arr, n, 0, n - 1, 0);
    // cout << s1 << " ";
    cout << (2 * s1 - sum);
}