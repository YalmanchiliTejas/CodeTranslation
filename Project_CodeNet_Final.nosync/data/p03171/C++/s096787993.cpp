/*
kaafi fucked up
*/
#define SET

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#define DEBUG

#include <bits/stdc++.h>
#include <string>
#define pb push_back
#define mp make_pair
#define f(i, a, b) for (long long i = a; i < b; i++)
#define revf(i, b, a) for (int i = b; i >= a; i--)
#define srt(v) sort(v.begin(), v.end())
#define rev_srt(v) sort(v.rbegin(), v.rend())
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

#ifdef SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multi_set;

#endif

#define nl '\n'
#define sp " "
#define precision(x) cout << fixed << setprecision(x);
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

template <typename T>
void debugv(vector<T> a)
{
#ifdef DEBUG
    for (auto i : a)
    {
        cout << i << sp;
    }
    cout << nl;
    return;
#endif
    return;
}

template <typename T>
void debuga(T *a, int n, int beg = 0)
{
#ifdef DEBUG
    f(i, beg, beg + n)
    {
        cout << a[i] << sp;
    }
    cout << nl;
    return;
#endif
    return;
}

void logg(string s)
{
#ifdef DEBUG
    cout << s << nl;
#endif
}

template <class T>
inline bool remax(T &a, T b)
{
    return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool remin(T &a, T b)
{
    return a > b ? a = b, 1 : 0;
}

ll md = 1000000007;
// const ll MXSZ= (ll)5e5;
// ll fact[MXSZ];
// ll mi[MXSZ];

// ll my_gcd(ll n, ll m)
// {
//     if (n % m == 0)
//         return m;
//     if (n < m)
//         swap(n, m);
//     while (m > 0)
//     {
//         n = n % m;
//         swap(n, m);
//     }
//     return n;
// }

ll pw(ll a, ll b)
{
    ll c = 1, m = a % md;
    while (b)
    {
        if (b & 1)
            c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}

ll modinv(ll n)
{
    return pw(n, md - 2);
}

inline ll add(ll a, ll b)
{
    return (md + a % md + b % md) % md;
}
inline ll subt(ll a, ll b)
{
    return (a % md - b % md + md) % md;
}
inline ll mult(ll a, ll b)
{
    return (1ll * (a % md) * (b % md)) % md;
}

// ll ncr(int n, int r)
// {
//     if (!n)
//         return 1;
//     return mult(fact[n], mult(mi[r], mi[n - r]));
// }

// void pre()
// {
//     fact[0] = 1;
//     ll lim = MXSZ;
//     f(i, 1, lim) fact[i] = mult(i, fact[i - 1]);

//     f(i, 0, lim) mi[i] = modinv(fact[i]);
//     // f(i, 0, 10) cout << mi[i] << sp;
//     // cout << nl;
// }
template <class T>
T myceil(T a, T b)
{
    if (a % b)
        return (a / b) + 1;
    else
        return a / b;
};

ll dp[3003][3003][2][2];
bool vis[3003][3003][2];
ll a[3003];
ll n;

ll* solve(ll l, ll r, ll p)
{
    if (vis[l][r][p])
        return dp[l][r][p];
    vis[l][r][p] = 1;
    
    if(l==r)
    {
        dp[l][r][p][p]=a[l];
        return dp[l][r][p];
    }

    if(a[l]+solve(l+1,r,1-p)[p] > a[r]+solve(l,r-1,1-p)[p]) 
    {
        dp[l][r][p][p]=a[l]+solve(l+1,r,1-p)[p];
        dp[l][r][p][1-p]=solve(l+1,r,1-p)[1-p];
    }else
    {
        dp[l][r][p][p]=a[r]+solve(l,r-1,1-p)[p];
        dp[l][r][p][1-p]=solve(l,r-1,1-p)[1-p];
    }
    return dp[l][r][p];
    
}

void solvetestcase(ll tcn)
{
    cin >> n;
    f(i, 0, n) cin >> a[i];
    cout<<solve(0,n-1,0)[0]-solve(0,n-1,0)[1]<<nl;
}

int main()
{
    fio;
    int t = 1;
    //cin >> t;
    //pre();
    f(i, 1, t + 1)
    {
        //cout << "Case #" << i << ": ";
        solvetestcase(i);

        //cout << nl;
    }
    return 0;
};