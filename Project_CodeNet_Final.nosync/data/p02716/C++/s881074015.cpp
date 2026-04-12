#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll long long
#define ld long double

#define pb push_back
#define ins insert
#define er erase

#define f(i, a, b) for (int i = a; i < b; ++i)
#define rf(i, a, b) for (int i = a; i >= b; --i)
#define mem(a, b) memset(a, b, sizeof(a))

#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vst vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define mxe max_element
#define mne min_element

#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(), v.rend())

#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second

#define bs bitset
#define bpc(a) __builtin_popcount(a)

#define mii map<int, int>
#define mll map<ll, ll>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>

#define si set<int>
#define sll set<ll>
#define spii set<pii>
#define spll set<ll>
#define usi unordered_set<int>
#define usll unordered_set<ll>

#define pqi priority_queue<int>
#define pqll priority_queue<ll>

#define dbg(a, st, end)                   \
    f(i, st, end + 1) cerr << a[i] << sp; \
    cerr << nl;
#define pnt(a, st, end)                   \
    f(i, st, end + 1) cout << a[i] << sp; \
    cout << nl;
#define dbgc(a)          \
    for (auto y : a)     \
        cerr << y << sp; \
    cerr << nl;
#define dbgm(a)                            \
    for (auto y : a)                       \
        cerr << y.ff << "," << y.ss << sp; \
    cerr << nl;

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)

#define nl "\n"
#define sp " "

using namespace std;
using namespace std::chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
#define ok order_of_key
#define fo find_by_order

int md = 1000000007;
//ll md = 998244353;

ll pw(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m);
        m = (m * m);
        b /= 2;
    }
    return c;
}

ll pwmd(ll a, ll b)
{
    ll c = 1, m = a;
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
    return pwmd(n, md - 2);
}

ll my_ceil(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}

ll nc2(ll n)
{
    return (1ll * n * (n - 1)) / 2;
}

int my_log(ll n, int b)
{
    ll i = 1;
    int ans = 0;
    while (1)
    {
        if (i > n / b)
            break;
        i *= b;
        ans++;
    }
    return ans;
}

inline int nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
    int ret = 0;
    bool f = 0;
    char ch = nc();
    while (ch > '9' || ch < '0')
        f ^= ch == '-', ch = nc();
    while (ch <= '9' && ch >= '0')
        ret = ret * 10 + ch - '0', ch = nc();
    return f ? -ret : ret;
}

inline ll add(ll a, ll b) { return (((a >= md) ? a % md : a) + ((b >= md) ? b % md : b) + md) % md; }
inline ll subt(ll a, ll b) { return (a - b + md) % md; }
inline ll mult(ll a, ll b) { return (1ll * ((a >= md) ? a % md : a) * ((b >= md) ? b % md : b)) % md; }

inline bool kthbit(ll n, int k) { return (n >> k) & 1; }
inline ll setkthbit(ll n, int k) { return n | (1ll << k); }
inline ll unsetkthbit(ll n, int k) { return n & ~(1ll << k); }
inline ll flipkthbit(ll n, int k) { return n ^ (1ll << k); }

//LET'S PLAY THE GAME!!

const int N = 200009;
ll a[N], prefo[N], suffe[N], cache[N], n;

ll dp(int idx)
{
    if (idx > n)
        return 0;
    if (cache[idx] != -1)
        return cache[idx];
    if (idx % 2)
        return cache[idx] = a[idx] + dp(idx + 2);
    return cache[idx] = a[idx] + max(dp(idx + 3), dp(idx + 2));
}

int main()
{
    fast;

    ll l, r, e, h, k;
    ll m, x, q, c;

    string s, t;

    auto start = high_resolution_clock::now();

    int tcnt = 0;
    int tests = 1;
    //cin>>tests;

    while (tests--)
    {
        //cout << "Case #" << ++tcnt << ": ";
        cin >> n;
        f(i, 1, 1 + n) cin >> a[i];
        if (n % 2 == 0)
        {
            ll prefo[n + 1], suffe[n + 1];
            prefo[1] = a[1];
            suffe[n] = a[n];
            f(i, 3, n) if (i % 2) prefo[i] = prefo[i - 2] + a[i];
            rf(i, n - 2, 1) if (i % 2 == 0) suffe[i] = suffe[i + 2] + a[i];
            ll ans = max(prefo[n - 1], suffe[2]);
            f(i, 1, 1 + n) if (i % 2 && i + 3 <= n) ans = max(ans, prefo[i] + suffe[i + 3]);
            cout << ans;
            return 0;
        }
        mem(cache, -1);
        ll mno = a[1];
        prefo[1] = a[1];
        f(i, 3, 1 + n) if (i % 2) prefo[i] = prefo[i - 2] + a[i], mno = min(mno, a[i]);
        ll ans = max(prefo[n] - mno, dp(2));
        f(i, 1, 1 + n)
        {
            if (i + 3 > n)
                continue;
            if (i % 2 == 0)
                continue;
            ans = max(ans, prefo[i] + dp(i + 3));
        }
        //f(i, 2, n + 1) if (i % 2 == 0) cout << dp(i) << sp;
        cout << ans;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: "
         << duration.count() / 1000000.0 << "seconds" << nl;
    return 0;
}

// AND THE GAME IS OVER !!