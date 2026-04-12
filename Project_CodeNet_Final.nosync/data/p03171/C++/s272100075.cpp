#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    if(n == 1)
    {
        cout << A[0] << '\n';
        return 0;
    }
    
    vector<ll> prefixSum(n);
    prefixSum[0] = A[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1]+A[i];
    }
    
    vector<vector<ll>> dp(n,vector<ll>(n));
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = A[i];
    }
    
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            ll sum1 = prefixSum[j]-prefixSum[i];
            ll sum2 = prefixSum[j-1];
            if(i > 0)
            {
                sum2 -= prefixSum[i-1];
            }
            
            dp[i][j] = max(A[i]+sum1-dp[i+1][j], A[j]+sum2-dp[i][j-1]);
        }
    }
    
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    ll X = max(A[0]+prefixSum[n-1]-prefixSum[0]-dp[1][n-1], A[n-1]+prefixSum[n-2]-dp[0][n-2]);
    ll Y = prefixSum[n-1]-X;
    
    // cout << A[0]+prefixSum[n-1]-prefixSum[0]-dp[1][n-1] << " " << A[n-1]+prefixSum[n-2]-dp[0][n-2] << '\n';
    cout << X-Y << '\n';
    
    return 0;
}