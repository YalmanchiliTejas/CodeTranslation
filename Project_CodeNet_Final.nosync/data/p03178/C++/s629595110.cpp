#include <iostream>
#include <cstring>
#define nmax 10005
using namespace std;
const int mod = 1e9 + 7;

long long dp[nmax][2][105];
int n, d;
string s;

long long solve(int pos, int eq, int rest)
{
    if(pos == n) {
        if (rest == 0)
            return 1;
        return 0;
    }
    if(dp[pos][eq][rest] != -1)
        return dp[pos][eq][rest];
    int lim;
    long long tot = 0;

    if (eq)
        lim = s[pos] - '0';
    else
        lim = 9;

    for(int i = 0; i <= lim; i++)
        tot += solve(pos + 1, eq && (i == lim), (rest + i) % d );

    tot %= mod;
    if (tot < 0)
        tot += mod;
    dp[pos][eq][rest] = tot;

    return tot;

}

int main()
{
    cin >> s;
    cin >> d;
    n = s.size();

    memset(dp,-1,sizeof(dp));

    long long ans = solve(0,1,0) - 1;

    if (ans < 0)
        ans += mod;

    cout << ans << endl;

    return 0;

}