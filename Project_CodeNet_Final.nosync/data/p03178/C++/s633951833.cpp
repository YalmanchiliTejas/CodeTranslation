#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
string K;
int D;
const ll MOD = 1e9 + 7;

ll dp[11111][2][111];

ll rec(int n, int flag, int sum)
{   
    if(dp[n][flag][sum] != -1) return dp[n][flag][sum];
    if(n == 0)
    {
        if(sum == 0) return dp[0][flag][0] = 1;
        else return dp[0][flag][sum] = 0;
    }

    ll res = 0;
    int digit = K[N - n] - '0';
    if(flag == 1)
    {   
        res += rec(n - 1, 1, (sum + digit) % D) % MOD;
        res %= MOD;
        for(int i = 0; i < digit; i++)
        {
            res += rec(n - 1, 0, (sum + i) % D) % MOD;
            res %= MOD;
        }
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            res += rec(n - 1, 0, (sum + i) % D) % MOD;
            res %= MOD;
        }
    }
    return dp[n][flag][sum] = res ;
}

int main()
{
    cin >> K >> D;
    N = K.length();
    memset(dp, -1, sizeof(dp));
    ll res = rec(N, 1, 0) - 1;
    if(res < 0) res += MOD;
    cout << res << endl; //0の時は含めない。
}