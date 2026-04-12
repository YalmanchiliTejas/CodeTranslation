#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

string k;
int d;
long long dp[10001][2][100];
bool sht[10001][2][100];

long long rec(int pos, int free, int csum)
{
    if (sht[pos][free][csum]) return dp[pos][free][csum];
    sht[pos][free][csum] = 1;
    
    if (pos == k.size()) return dp[pos][free][csum] = (csum == 0);
    
    if (free)
    {
        for (int i = 0; i != 10; ++i)
            dp[pos][free][csum] += rec(pos + 1, 1, (csum + i) % d);
        return dp[pos][free][csum] %= MOD;
    }
    else
    {
        for (int i = 0; i != k[pos]; ++i)
            dp[pos][free][csum] += rec(pos + 1, 1, (csum + i) % d);
        return (dp[pos][free][csum] += rec(pos + 1, 0, (csum + k[pos]) % d)) %= MOD;
    }
}

int main()
{    
    cin >> k >> d;
    for (int i = 0; i != k.size(); ++i)
        k[i] -= '0';
    
    cout << (rec(0, 0, 0) + MOD - 1) % MOD;
}