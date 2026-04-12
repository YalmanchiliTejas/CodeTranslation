#include <bits/stdc++.h>

#define endl '\n'
#define left aba
#define right abc
#define oo if(LOG)
#define pb push_back
#define FIO ios_base::sync_with_stdio(0); cin.tie(0)

#ifdef LOCAL
#define LOG 1
#else
#define LOG 0
#endif

using namespace std;

const int DIG = 10005, MAXD = 105, MOD = (int)(1e9) + 7;

string k;
int d, n;

inline void add(long long &aa, long long bb) {aa += bb; aa %= MOD;}

long long dp[DIG][2][MAXD];

long long go(int pos, bool fl, int sum) {
    if(pos >= n) return sum % d == 0 ? 1 : 0;
    if(dp[pos][fl][sum % d] != -1) return dp[pos][fl][sum % d];

    long long ret = 0;
    for(int i = 0; i <= 9; ++i) {
        if(fl || (!fl && i <= k[pos] - '0')) {
            long long nxt = go(pos + 1, fl | (i < k[pos] - '0'), sum + i);
            add(ret, nxt);
        }
    }
    return dp[pos][fl][sum % d] = ret;
}

int main() {
    FIO;

    cin >> k >> d;
    n = (int)k.size();
    for(int i = 0; i < DIG; ++i) for(int j = 0; j < 2; ++j) for(int l = 0; l < MAXD; ++l) dp[i][j][l] = -1;
    long long ans = go(0, 0, 0) - 1;
    if(ans < 0) ans += MOD;
    cout << ans << endl;

    oo cout << "Time: " << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
