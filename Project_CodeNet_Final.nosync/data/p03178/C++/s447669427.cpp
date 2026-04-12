#include <bits/stdc++.h>

using namespace std;
#define long long long

int const N = 1e4 + 10;
int const MOD = 1e9 + 7;

int n, d, dp[N][110][2];
// dp[index of digit][remainder][limited or not]
char s[N];

int Solve(int index, int remainder, int smaller)
{
    if (index == n) {
        if (!remainder) return 1;
        else return 0;
    }

    if (dp[index][remainder][smaller] != -1) return dp[index][remainder][smaller];

    int limit = 9;
    long init_cnt = 0;
    if (smaller) limit = s[index] - '0';
    for (int i = 0; i <= limit; ++i) {
        int check = (i < s[index] - '0' ? 0 : smaller);
        (init_cnt += Solve(index + 1, (remainder + i) % d, check)) %= MOD;
    }
    dp[index][remainder][smaller] = init_cnt;
    return init_cnt;
}

int main()
{
//    freopen("tam.inp", "r", stdin);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    cin >> s >> d;
    n = strlen(s);

    memset(dp, -1, sizeof(dp));
    cout << (Solve(0, 0, 1) - 1 + MOD) % MOD;

    return 0;
}
