#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define endl '\n'
#define debug(...)
#else
#define debug(...) __VA_ARGS__
#endif
#define debugf(...) debug(printf(__VA_ARGS__);)

using ll = long long;
const int N = 3123;
constexpr ll mod = 998244353;

int a[N];

void add(ll& x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}

ll dp[N][N];
ll ps[N];

int (((((main)))))() <%
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][a[i]] += i;
        for (int w = s; w >= a[i]; w--)
            add(dp[i][w], ps[w - a[i]]);

        for (int w = 0; w <= s; w++)
            add(ps[w], dp[i][w]);
    }

    debug(
        for (int i = 1; i <= n; i++)
            cout << dp[i][s] << ' ';
        cout << endl;
        for (int w = 1; w <= s; w++)
            cout << ps[w] << ' ';
        cout << endl;
    )

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, dp[i][s] * ll(n - i + 1) % mod);
    }

    cout << ans << endl;


    return 0;
%>