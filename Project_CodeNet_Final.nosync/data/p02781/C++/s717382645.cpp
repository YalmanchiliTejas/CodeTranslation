#include <bits/stdc++.h>
using namespace std;

string A;
long long dp[102][2][4];

long long solve(int pos, int lo, int K)
{
    if(K < 0)
        return 0;
    
    if(pos == A.size())
        return K == 0;
    
    if(dp[pos][lo][K] != -1)
        return dp[pos][lo][K];
    
    int digit = A[pos] - '0';
    long long ans = 0;

    for(int i=0; i<10; i++)
    {
        if(lo == 0 && i > digit)
            break;
        
        ans += solve(pos+1, (lo | (i < digit)), K - (i > 0));
    }

    return dp[pos][lo][K] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int K;
    cin >> A >> K;
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0, K) << "\n";
    return 0;
}
