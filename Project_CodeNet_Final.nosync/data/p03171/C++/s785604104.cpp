#include<bits/stdc++.h>
using namespace std;

// int score(int i, int j, vector<int>&A)
// {
//     if(i > j)
//         return 0;
//     if(i + 1 == j)
//         return max(A[i] , A[j]) - min(A[i], A[j]);
//     if(dp[i][j] != INT_MIN)
//         return dp[i][j];
//     int scorei = A[i] - score(i + 1, j, A);
//     int scorej = A[j] - score(i, j - 1, A);
//     dp[i][j] = max(scorei, scorej);
//     return max(scorei, scorej);
// }

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    vector<vector<long>> dp(n, vector<long>(n));
    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if(len == 1)
                dp[i][j] = A[i];
            else if(len == 2)
                dp[i][j] = max(A[i] , A[j]) - min(A[i], A[j]);
            else
            {
                long scorei = A[i] - dp[i + 1][j];
                long scorej = A[j] - dp[i][j - 1];
                dp[i][j] = max(scorei, scorej);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}