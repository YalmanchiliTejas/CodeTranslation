const int N = 505;
const int LG = 21;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <bitset>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(N);
    __ufact.resize(N);
    __rev.resize(N);
    __rev[1] = 1;
    for (int i = 2; i < N; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < N; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

void __fast_IO()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
}

//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**
//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**

int n;
unsigned long long int s[N], t[N], u[N], v[N], a[N][N], deg2[64];

void solve(int bit)
{
    vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) if (u[i] & (1ll << bit)) r[i] = 1;
    for (int i = 0; i < n; i++) if (v[i] & (1ll << bit)) c[i] = 1;
    int g0r = 0, g0c = 0, g1r = 0, g1c = 0;
    for (int i = 0; i < n; i++) if (s[i] == 1 && r[i] == 0) g0r++;
    for (int i = 0; i < n; i++) if (s[i] == 0 && r[i] == 1) g1r++;
    for (int i = 0; i < n; i++) if (t[i] == 1 && c[i] == 0) g0c++;
    for (int i = 0; i < n; i++) if (t[i] == 0 && c[i] == 1) g1c++;
    //cout << g0r << " " << g0c << " " << g1r << " " << g1c << endl;
    if (g0r && g1c) cout << -1, exit(0);
    if (g1r && g0c) cout << -1, exit(0);
    if (g1r && g1c)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((r[i] == 1 && s[i] == 0) || (c[j] == 1 && t[j] == 0)) a[i][j] += deg2[bit];
                else a[i][j] += 0;
            }
        }
        return;
    }
    if (g0r && g0c)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((r[i] == 0 && s[i] == 1) || (c[j] == 0 && t[j] == 1)) a[i][j] += 0;
                else a[i][j] += deg2[bit];
            }
        }
        return;
    }
    if (!g0c && !g1c && !g0r && !g1r)
    {
        for (int i = 0; i < n; i++)
        {
            a[i][i] += deg2[bit];
        }
        return;
    }
    if (g0c || g1c)
    {
        if ((g0c + g1c) != n && (g0c == n - 1 || g1c == n - 1))
        {
            if (g0c == n - 1)
            {
                int other_col = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (c[j] == 0 && t[j] == 1) a[i][j] += 0;
                        else other_col = j;
                    }
                }
                int t = -1;
                for (int i = 0; i < n; i++)
                {
                    if (r[i] == 0) t = i;
                }
                if (t != -1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (i != t) a[i][other_col] += deg2[bit];
                    }
                }
                else if (c[other_col] == 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        a[i][other_col] += deg2[bit];
                    }
                }
                else cout << -1, exit(0);
            }
            else
            {
                int other_col = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (c[j] == 1 && t[j] == 0) a[i][j] += deg2[bit];
                        else other_col = j;
                    }
                }
                int t = -1;
                for (int i = 0; i < n; i++)
                {
                    if (r[i] == 1) t = i;
                }
                if (t != -1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (i == t) a[i][other_col] += deg2[bit];
                    }
                }
                else if (c[other_col] == 0)
                {
                    for (int i = 0; i < n; i++)
                    {
                        //a[i][other_col] += deg2[bit];
                    }
                }
                else cout << -1, exit(0);
            }
            return;
        }
        if (g0c == 0 || g1c == 0)
        {
            vector<int> others;
            for (int j = 0; j < n; j++)
            {
                if (c[j] == 1 && t[j] == 0) for (int i = 0; i < n; i++) a[i][j] += deg2[bit];
                else if (c[j] == 0 && t[j] == 1) for (int i = 0; i < n; i++) a[i][j] += 0;
                else others.push_back(j);
            }
            if (others.size())
            {
                for (int i = 0; i + 1 < others.size(); i++) a[n - 1][others[i]] += deg2[bit];
                for (int i = 0; i < n - 1; i++) a[i][others.back()] += deg2[bit];
            }
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (c[j] == 1 && t[j] == 0) for (int i = 0; i < n; i++) a[i][j] += deg2[bit];
            else if (c[j] == 0 && t[j] == 1) for (int i = 0; i < n; i++) a[i][j] += 0;
            else for (int i = 0; i < n; i++) a[i][j] += (i == n - 1) * deg2[bit];
        }
        return;
    }
    if (g0r || g1r)
    {
        if (g0r + g1r != n && (g0r == n - 1 || g1r == n - 1))
        {
            if (g0r == n - 1)
            {
                int other_row = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (r[i] == 0 && s[i] == 1) a[i][j] += 0;
                        else other_row = i;
                    }
                }
                int t = -1;
                for (int j = 0; j < n; j++)
                {
                    if (c[j] == 0) t = j;
                }
                if (t != -1)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j != t) a[other_row][j] += deg2[bit];
                    }
                }
                else if (r[other_row] == 1)
                {
                    for (int j = 0; j < n; j++)
                    {
                        a[other_row][j] += deg2[bit];
                    }
                }
                else cout << -1, exit(0);
            }
            else
            {
                int other_row = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (r[i] == 1 && s[i] == 0) a[i][j] += deg2[bit];
                        else other_row = i;
                    }
                }
                int t = -1;
                for (int j = 0; j < n; j++)
                {
                    if (c[j] == 1) t = j;
                }
                if (t != -1)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j == t) a[other_row][j] += deg2[bit];
                    }
                }
                else if (r[other_row] == 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        ;//a[other_row][j] += deg2[bit];
                    }
                }
                else cout << -1, exit(0);
            }
            return;
        }
        if (g0c == 0 || g1c == 0)
        {
            vector<int> others;
            for (int i = 0; i < n; i++)
            {
                if (r[i] == 1 && s[i] == 0) for (int j = 0; j < n; j++) a[i][j] += deg2[bit];
                else if (r[i] == 0 && s[i] == 1) for (int j = 0; j < n; j++) a[i][j] += 0;
                else others.push_back(i);
            }
            if (others.size())
            {
                for (int i = 0; i + 1 < others.size(); i++) a[others[i]][n - 1] += deg2[bit];
                for (int i = 0; i < n - 1; i++) a[others.back()][i] += deg2[bit];
            }
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (r[i] == 1 && s[i] == 0) for (int j = 0; j < n; j++) a[i][j] += deg2[bit];
            else if (r[i] == 0 && s[i] == 1) for (int j = 0; j < n; j++) a[i][j] += 0;
            else for (int j = 0; j < n; j++) a[i][j] += (j == n - 1) * deg2[bit];
        }
        return;
    }
    exit(1);
}

void check()
{
    for (int i = 0; i < n; i++)
    {
        unsigned long long int x = a[i][0];
        if (s[i] == 0) for (int j = 0; j < n; j++) x &= a[i][j];
        if (s[i] == 1) for (int j = 0; j < n; j++) x |= a[i][j];
        if (x != u[i]) cout << -1, exit(0);
    }
    for (int j = 0; j < n; j++)
    {
        unsigned long long int x = a[0][j];
        if (t[j] == 0) for (int i = 0; i < n; i++) x &= a[i][j];
        if (t[j] == 1) for (int i = 0; i < n; i++) x |= a[i][j];
        if (x != v[j]) cout << -1, exit(0);
    }
}

signed main()
{
    deg2[0] = 1;
    for (int i = 1; i < 64; i++) deg2[i] = deg2[i - 1] * 2;
    __fast_IO();
    cin >> n;
    forn(i, n) cin >> s[i];
    forn(i, n) cin >> t[i];
    forn(i, n) cin >> u[i];
    forn(i, n) cin >> v[i];
    if (n == 1)
    {
        if (u[0] == v[0])
        {
            cout << u[0];
            return 0;
        }
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 64; i++) solve(i);
    check();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/
