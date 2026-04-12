#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, mod = 1e9 + 7;
string s;
int d, dp[N][101][2];

int solve (int pos, int rem, bool smaller) {
    if (pos == s.size() ) return (!rem);
    int &ret = dp[pos][rem][smaller];
    if (ret != -1) return ret;
    ret = 0;
    int lim = 9;
    if (!smaller) lim = s[pos] - '0';
    for (int i = 0; i <= lim; ++i) ret = (ret + solve(pos + 1, (rem + i) % d, max(smaller, (i < lim) ) ) ) % mod;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> d;

    memset(dp, -1, sizeof dp);
    cout << (solve(0, 0, 0) + mod - 1) % mod;

    return 0;
}
