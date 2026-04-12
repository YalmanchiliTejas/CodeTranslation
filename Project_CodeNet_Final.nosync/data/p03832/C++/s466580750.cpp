//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

const int mod = (int)1e9 + 7;
void add (int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int mult (int a, int b)
{
    return (ll)a * b % mod;
}

void solve (int n)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vi dp(n + 1, 0);
    vi ndp(n + 1);
    dp[0] = 1;

    const int B = n + 1;
    vvi C(B, vi(B));
    for (int i = 0; i < B; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j];
            add(C[i][j], C[i - 1][j - 1]);
        }
    }

    vi inv(B, 1);
    for (int i = 2; i < B; i++)
    {
        inv[i] = mod - mult(mod / i, inv[mod % i]);
        assert(mult(inv[i], i) == 1);
    }

    for (int i = a; i <= b; i++)
    {
        fill(ALL(ndp), 0);
        for (int j = 0; j <= n; j++)
        if (dp[j])
        {
            int coef = 1;
            for (int g = 0; g * i + j <= n; g++)
            {
                if (g != 0)
                {
                    coef = mult(coef, C[g * i + j][(g - 1) * i + j]);
                    coef = mult(coef, inv[g]);
                }
                if (g == 0 || (c <= g && g <= d))
                    add(ndp[g * i + j], mult(coef, dp[j]));
            }
        }

        copy(ALL(ndp), dp.begin());
    }

    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}
