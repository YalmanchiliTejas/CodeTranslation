#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

string S;
long long dp[10001][2][101];

long long solve(int N, int lo, int rem, int K)
{
    if(N == S.size())
        return (rem == 0);
    
    if(dp[N][lo][rem] != -1)
        return dp[N][lo][rem];
    
    int val = S[N]-'0';
    long long ans = 0;
    
    for(int i=0; i<10; i++)
    {
        if(lo == 0 && i > val)
            break;
        
        ans += solve(N+1, (lo | (i < val)), (rem + i) % K, K);
    }
    
    return dp[N][lo][rem] = ans % MOD;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    
    int K;
    cin >> S >> K;
    
    memset(dp, -1, sizeof(dp));
    
    cout << (solve(0, 0, 0, K) + MOD - 1) % MOD << "\n";
    return 0;
}