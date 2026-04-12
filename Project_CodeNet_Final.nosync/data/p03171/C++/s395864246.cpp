#include <bits/stdc++.h>
using namespace std;

const long long inf = (long long) 1e18;

int A[3003];
long long dp[3003][3003];

long long solve(int L, int R, int f)
{
    if(L == R)
        return A[L] * f;
    
    if(dp[L][R] != inf)
        return dp[L][R];
    
    long long ans = 0;
    
    if(f == 1)
    {
        ans = -inf;
        ans = max(ans, solve(L+1, R, -1) + A[L]);
        ans = max(ans, solve(L, R-1, -1) + A[R]);
    }
    else
    {
        ans = inf;
        ans = min(ans, solve(L+1, R, 1) - A[L]);
        ans = min(ans, solve(L, R-1, 1) - A[R]);
    }
    
    return dp[L][R] = ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++)
        cin >> A[i];
    
    for(int i=1; i<=N; i++)
        for(int j=i; j<=N; j++)
            dp[i][j] = inf;
    
    cout << solve(1, N, 1) << "\n";
    return 0;
}