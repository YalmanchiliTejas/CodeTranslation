#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

const int N = 1000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

ll bin_pow(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return res;
}

int C[N + 1][N + 1];

void init_C()
{
    rep(i, 1, N + 1)
        C[0][i] = 0;
    rep(i, 0, N + 1)
        C[i][0] = 1;
    rep(i, 1, N + 1)
        rep(j, 1, i + 1)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
}

ll fact[1000 + 1], rfact[1000 + 1];

void init()
{
    fact[0] = 1;
    rep(i, 1, 1000 + 1)
        fact[i] = (fact[i - 1] * i) % MOD;
    rep(i, 0, 1000 + 1)
        rfact[i] = bin_pow(fact[i], MOD - 2);
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int dp[N + 1][N + 1];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    init();
    init_C();
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    dp[0][0] = 1;
    rep(i, 0, n + 1)
        rep(j, 0, n)
        {
            ll v = 1;
            rep(cnt, 0, (n - i) / (j + 1) + 1)
            {
                if (cnt == 0 || ((j + 1) >= a && (j + 1) <= b && cnt >= c && cnt <= d))
                    add(dp[i + (j + 1) * cnt][j + 1], 1LL * dp[i][j] * C[i + (j + 1) * cnt][i] % MOD * fact[(j + 1) * cnt] % MOD * rfact[cnt] % MOD * v % MOD);
                v = (v * rfact[j + 1]) % MOD;
            }
        }
    /*rep(i, 0, n + 1)
    {
        rep(j, 0, n + 1)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    cout << dp[n][n] << "\n";
    return 0;
}
