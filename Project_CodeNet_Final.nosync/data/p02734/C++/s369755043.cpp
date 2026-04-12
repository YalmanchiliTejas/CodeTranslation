// Copyright [2020] <unknown>
#include <bits/stdc++.h>
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define dbg(x...) { cerr << "\033[32;1m" << #x << " -> "; err(x); }
void err() { cerr << "\033[39;0m" << endl; }
template<typename T, typename... A>
void err(T a, A... x) { cerr << a << ' '; err(x...); }
#else
#define dbg(...)
#endif

#define sz(x) ((int)x.size())

typedef long long LL;

const int N = 3050, MOD = 998244353;

int n, s, a[N], g[N][N], h[N][N];

int ta[N], tb[N];
inline void update(int &a, int b) {
    a = (a + b)% MOD;
}

int main(int argc, char const *argv[]) {
    // code
    scanf("%d%d", &n, &s);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        // dp[i][0] = 1;
    }
    h[0][0] = g[0][0] = 1;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<=s; ++j) {
            update(h[i][j], h[i-1][j]);
            if (j > a[i])
                update(h[i][j], h[i-1][j-a[i]]);
        }
        update(h[i][a[i]], i);
        for (int j=0; j<=s; ++j) {
            update(g[i][j], g[i-1][j]);
            update(g[i][j], h[i][j]);
        }
    }


    cout << g[n][s] << endl;
    return 0;
}
