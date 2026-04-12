/***********************************************
 *                                             *
 *   author: raghav_0901 (Raghav Dalmia)       *
 *   updated on: 19-09-2020,  6:54:37 pm IST   *
 *                                             *
\***********************************************/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long int
const int mod = (1e9) + 7;

// #define cerr  \
//     if (false) \
//     cerr
#define error(args...)                             \
    {                                              \
        string _s = #args;                         \
        replace(_s.begin( ), _s.end( ), ',', ' '); \
        stringstream _ss(_s);                      \
        istream_iterator<string> _it(_ss);         \
        err(_it, args);                            \
    }
void err(istream_iterator<string> it)
{
    cerr << '\n';
    cerr.flush( );
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ", ";
    err(++it, args...);
}

void print( )
{
    cout << '\n';
    cout.flush( );
}
template <typename T, typename... Args>
void print(T a, Args... args)
{
    cout << a << ' ';
    print(args...);
}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

#define endl '\n'

#define f(i, begin, end) for (__typeof(end) i = (begin); i != (end); i += 1 - 2 * ((begin) > (end)))
#define ff(i, begin, end, fl) \
    for (__typeof(end) i = (begin); i != (end) && fl; i += 1 - 2 * ((begin) > (end)))

#define mem(arr, val) memset(arr, val, sizeof(arr));
#define ps(x, y) fixed << setprecision(y) << x
#define inf INT_MAX

#define fi first
#define se second
#define mpr(a, b) make_pair(a, b)
typedef pair<int, int> pr;

#define pb emplace_back
#define _in(v)                      \
    {                               \
        for (auto &x : v) cin >> x; \
    }
#define _out(v)                            \
    {                                      \
        for (auto x : v) cout << x << ' '; \
        cout << '\n';                      \
    }
typedef vector<int> vec;
#define all(x) (x).begin( ), (x).end( )
#define allr(x) (x).rbegin( ), (x).rend( )
#define each(i, v) for (auto &i : v)
#define sumv(v) accumulate(v.begin( ), v.end( ), 0)

template <typename T>
T max(vector<T> &v)
{
    return *max_element(all(v));
}

template <typename T>
T min(vector<T> &v)
{
    return *min_element(all(v));
}

#define setbits(x) __builtin_popcountll(x)
#define numbits(x) (64 - __builtin_clzll(x))
#define zerobit(x) __builtin_ctzll(x)
#define log2(x) (63 - __builtin_clzll(x))

#define pi 3.1415926535897932384626433

inline bool isPow2(int x) { return x && (!(x & (x - 1))); }
inline int n_sum(int n) { return (n * (n + 1)) >> 1; }

int pow(int a, int b)
{
    int res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

inline int modinv(int k) { return pow(k, mod - 2); }
inline int add(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
inline int sub(int a, int b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }

inline int modinv(int k, int m) { return pow(k, m - 2); }
inline int add(int a, int b, int m) { return ((a % m) + (b % m)) % m; }
inline int sub(int a, int b, int m) { return ((a % m) - (b % m) + m) % m; }
inline int mul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

double sum( ) { return 0.0; }
template <typename T, typename... Args>
T sum(T a, Args... args)
{
    return a + sum(args...);
}

void _main(void);
signed main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    _main( );

    return 0;
}

//--------------------------- Main Function -----------------------

int n, m;

const int nx = (1e5) + 1;
int dp1[nx];
int dp2[nx];

void precompute( )
{
    // for (int i = 2; i <= m; i++) print(i, dp1[i], dp2[i]);

    for (int i = 2; i <= m; i++)
    {
        if (dp1[i] == 0)
        {
            dp1[i] = i;
            dp2[i] = 1;
            int prev = i;
            for (int j = i * i; j <= m; j *= j)
            {
                dp1[j] = dp1[prev] + j;
                dp2[j] = dp2[prev] + 1;
                prev = j;
            }
        }
    }
}

void _main(void)
{
    // code here
    int x;
    cin >> n >> x >> m;
    vector<bool> vis(m+1, 0);
    map<int, pr> mp;
    int ans = 0, cnt = 0;
    while (cnt < n && !vis[x])
    {
        mp[x] = mpr(ans, cnt);
        ans += x;
        cnt++;
        vis[x] = 1;
        x = mul(x, x, m);
        if (x == 0)
        {
            cout << ans;
            return;
        }
    }
    n -= cnt;
    if (n == 0)
    {
        cout << ans;
        return;
    }
    int prevs = ans - mp[x].first;
    int prevc = cnt - mp[x].second;
    ans += (prevs * (n / prevc));
    for (int i = 0; i < (n % prevc); i++)
    {
        ans += x;
        x = mul(x, x, m);
    }
    cout << ans;
    return;
}