#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using pii=std::pair<int,int>;
using namespace std;

const int maxdig = 1e4 + 5, maxd = 105;

int d, dp[maxdig][2][maxd];
string k;
vector<int> digits;

int solve(int pos, int anygood, int modsum)
{
    if(pos == digits.size())
        return (modsum == 0);
    assert(pos < digits.size());
    if(dp[pos][anygood][modsum] == -1)
    {
        dp[pos][anygood][modsum] = 0;
        for(int i = 0; i < 10; i++)
            if((i <= digits[pos] || anygood))
                dp[pos][anygood][modsum] += solve(pos + 1, anygood | (i < digits[pos]), (modsum + i) % d);
        dp[pos][anygood][modsum] %= MOD;
    }
    return dp[pos][anygood][modsum];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> d;
    for(int i = 0; i < k.length(); i++)
        digits.push_back(k[i] - '0');
    for(int i = 0; i < digits.size(); i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < d; k++)
                dp[i][j][k] = -1;
    cout << (solve(0, 0, 0) - 1 + MOD) % MOD << "\n";
    return 0;
}