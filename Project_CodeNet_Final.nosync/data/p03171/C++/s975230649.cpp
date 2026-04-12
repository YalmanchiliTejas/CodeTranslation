#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[3001][3001];
ll a[3000];
ll game(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (r - l == 0)
        return a[l];
    return dp[l][r] = max(a[l] - game(l + 1, r), a[r] - game(l, r - 1));
}

int main()
{
    rep(l, 3001) rep(r, 3001) dp[l][r] = -1;
    int n;
    cin >> n;

    rep(i, n) cin >> a[i];

    OP(game(0, n - 1));

    return 0;
}