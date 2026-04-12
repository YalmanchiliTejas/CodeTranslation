#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (long long i = 0; i < (long long) (n); ++i)
#define pb emplace_back
#define endl '\n'

template<typename T> void _dbg(const char*_s,T _h) { cerr<<_s<<" = "<<_h<<"\n"; }

template<typename T, typename... Ts> void _dbg(const char*_s,T _h,Ts... _t) {
    for(int _b=0;((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',';)cerr<<*_s++;
    cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);
}

#define int long long

#ifdef LOCAL
    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 3 * 1000 + 17;
const int MOD = 998244353;

int n, s;
int a[N];
int dp[N][N][3];

bool read() {
    if (!(cin >> n >> s))
        return false;

    forn (i, n)
        cin >> a[i];

    return true;
}

void solve(int id = 0) {
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i)
        for (int w = 0; w <= s; ++w) {
            forn (j, 3)
                dp[i][w][j] %= MOD;

            dp[i + 1][w][0] += dp[i][w][0];
            dp[i + 1][w][1] += dp[i][w][0];

            if (w + a[i] <= s)
                dp[i + 1][w + a[i]][1] += dp[i][w][0];

            dp[i + 1][w][1] += dp[i][w][1];

            if (w + a[i] <= s)
                dp[i + 1][w + a[i]][1] += dp[i][w][1];

            dp[i + 1][w][2] += dp[i][w][1];

            dp[i + 1][w][2] += dp[i][w][2];
        }

    cout << (dp[n][s][2] + dp[n][s][1]) % MOD << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    //cin >> T;
    T = 1;

    while (read())
        solve(T++);

    return 0;
}
