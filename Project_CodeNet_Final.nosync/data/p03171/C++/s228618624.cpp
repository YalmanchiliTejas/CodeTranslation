#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector<lli> arr;
int count = 0;
lli solve(int start, int end, lli x, lli y, bool x_turn = true)
{
    //        cout<<x<<" "<<y<<"\n";
    //count++;
    if (start > end)
    {

        return x - y;
    }
    int res1, res2;

    if (x_turn)
    {
        if (start == end)
        {

            return (x + arr[start]) - y;
        }
        res1 = solve(start + 1, end, x + arr[start], y, !x_turn);
        res2 = solve(start, end - 1, x + arr[end], y, !x_turn);
        return max(res1, res2);
    }
    else
    {
        if (start == end)
        {
            return x - (arr[start] + y);
        }
        res1 = solve(start + 1, end, x, arr[start] + y, !x_turn);
        res2 = solve(start, end - 1, x, arr[end] + y, !x_turn);
        return min(res1, res2);
    }
}

lli solve2(int N)
{
    vector<vector<lli>> dp(N, vector<lli>(N, 0));
    for (int i = 0; i < N; i++)
        dp[i][i] = arr[i];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            dp[j][i + j] = max(arr[j] - dp[j + 1][i + j], arr[j + i] - dp[j][j + i - 1]);
        }
    }
    return dp[0][N - 1];
}
int main()
{
    int N;
    cin >> N;
    arr = vector<lli>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    //cout << solve(0, N - 1, 0, 0) << " ";
    cout<<solve2(N);
}