#define taskname ""

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define long long long

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, d, dp[N][110][2];
char s[N];

int solve(int index, int remainder, int smaller)
{
    if (index == n) return remainder == 0;
    if (dp[index][remainder][smaller] != -1) return dp[index][remainder][smaller];

    int limit = 9;
    if (smaller) limit = s[index] - '0';

    int res = 0;
    for (int i = 0; i <= limit; ++i) {
        int new_type = (i < limit ? 0 : smaller);
        res = (res + solve(index + 1, (remainder + i) % d, new_type)) % MOD;
    }

    dp[index][remainder][smaller] = res;
    return res;
}

int main()
{
//    freopen(taskname".INP", "r", stdin);
//    freopen(taskname".OUT", "w", stdout);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    cin >> s >> d;
    n = strlen(s);

    cout << (solve(0, 0, 1) - 1 + MOD) % MOD;

    return 0;
}
