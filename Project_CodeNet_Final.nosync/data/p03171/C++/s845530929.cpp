#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 0
#define dd if (DEBUG)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair((a), (b))
typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 3e+3+7;

// 00:20:00h

int main ()
{
    FASTIO;
    int i, j, n;
    cin >> n;
    vi A (n);
    trav (a, A)
        cin >> a;
    mll dp (n, vll (n));
    trav (v, dp)
        trav (a, v)
            a = 0;
    for (i = 0; i < n; ++i)
        dp[i][i] = A[i];
    for (i = 1; i < n; ++i)
        dp[i - 1][i] = max (A[i - 1], A[i]);
    for (i = 2; i < n; ++i)
    {
        for (j = i; j < n; ++j)
        {
            dp[j - i][j] = max (A[j] + min (dp[j - i][j - 2], dp[j - i + 1][j - 1]),
                    A[j - i] + min (dp[j - i + 1][j - 1], dp[j - i + 2][j]));
        }
    }
    dd for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            printf ("% 5lld", dp[i][j]);
        printf ("\n");
    }
    dd printf ("\n");
    if (sz(A) > 1)
        cout << dp[0][sz(A) - 1] - min (dp[0][sz(A) - 2], dp[1][sz(A) - 1]);
    else
        cout << dp[0][sz(A) - 1];
    cout << '\n';

    return 0;
}

