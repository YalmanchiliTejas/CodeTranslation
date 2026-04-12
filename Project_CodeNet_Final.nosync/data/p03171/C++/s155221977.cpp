#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <stack>
#define int long long
using namespace std;

int32_t main()
{
    int N;

    cin >> N;

    vector<int> arr(N);

    for (int &e : arr)
        cin >> e;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len <= N; l++) {
            int r = l + len;
            dp[l][r] = -2e18;
            dp[l][r] = max(dp[l][r], arr[l] - dp[l + 1][r]);
            dp[l][r] = max(dp[l][r], arr[r - 1] - dp[l][r - 1]);
        }
    }
    cout << dp[0][N] << endl;
}