#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD (int)(1e9 + 7)

int main()
{
    int n;
    cin >> n;
    ll nums[n];
    for (int q = 0; q < n; q++)
    {
        cin >> nums[q];
    }
    ll dp[n+3][n+3];
    for (int q = 0; q < n+3; q++)
    {
        dp[q][q]=0;
    }
    for (int q = 1; q <= n; q++)
    {
        for (int w = 0; w < n-q+1; w++)
        {
            int left = w;
            int right = w+q;
            dp[left][right] = max(nums[left]-dp[left+1][right], nums[right-1]-dp[left][right-1]);
        }
    }
    cout << dp[0][n];
    return 0;
}
