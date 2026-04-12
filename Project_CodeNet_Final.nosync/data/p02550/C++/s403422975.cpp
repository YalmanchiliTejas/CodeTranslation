#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define C continue;
#define R return

#define ull unsigned long long int
#define ll long long int
#define ld long double
#define D double

#define V vector
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<D>
#define vll vector<ll>
#define vull vector<ull>
#define vld vector<ld>

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vvd vector<vector<D>>
#define vvld vector<vector<ld>>

#define P pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pld pair<ld, ld>
#define F first
#define S second

#define vpld vector<pld>
#define vpii vector<pii>
#define vpll vector<pll>

#define vvpii vector<vector<pii>>
#define vvpll vector<vector<pll>>

#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>

#define mii map<int, int>
#define mll map<ll, ll>
#define mci map<char, int>
#define msi map<string, int>
#define mis map<int, string>

#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define umci unordered_map<char, int>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>

//IO
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define in1(x, n) f(i, n) cin >> x[i];
#define in2(x, n, m) f(i, n) f(j, m) cin >> x[i][j];
#define inp(x, n) f(i, n) cin >> x[i].F >> x[i].S;
#define out1(x, n)               \
    f(i, n) cout << x[i] << " "; \
    cout << "\n";
#define out2(x, n, m)                   \
    f(i, n)                             \
    {                                   \
        f(j, m) cout << x[i][j] << " "; \
        cout << "\n";                   \
    }
#define outp(x, n) f(i, n) cout << x[i].F << " " << x[i].S << "\n";
#define pp(n) printf("%.10Lf", n);
#define prdbl(val, precise) cout << fixed << setprecision(precise) << val << "\n";
#define dbg1(x) cout << " > " << #x << " = " << x << "\n";
#define dbg2(x, y) cout << " < " << #x << " = " << x << ", " << #y << " = " << y << endl;
#define line cout << "\n";

#define init(x, val) memset(x, val, sizeof(x)) //can be 0 or -1
#define mem(x, val) memset(x, val, sizeof(x))  //can be 0 or -1 only

//loops
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define loopr(i, a, b) for (ll i = a; i >= b; i--)
#define loops(i, a, b, step) for (ll i = a; i < b; i += step)
#define looprs(i, a, b, step) for (ll i = a; i >= b; i -= step)
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, n) for (ll i = 1; i <= n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0; i--)
#define fir(x, y) f(ll i = min(x, y); i <= max(x, y); i++)
#define firr(x, y) f(ll i = max(x, y); i <= min(x, y); i++)
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bgn(x) ((x).begin())
#define sz(x) ((x).size())
#define mxe(a) *(max_element(all(a))
#define mne(a) *(min_element(all(a))
#define lb lower_bound
#define ub upper_bound
#define rev reverse

#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define I insert

#define count_1(n) __builtin_popcountll(n)
#define sqr(x) ((x) * (x))
#define dist(a, b, p, q) sqrt((p - a) * (p - a) + (q - b) * (q - b))

#define mod1 1000000007
#define mod2 998244353

//functions

void yes()
{
    cout << "YES";
    //cout << "\n";
}

void no()
{
    cout << "NO";
    //cout << "\n";
}

ll pmod(ll a, ll mod = mod1) { return ((a) % mod + mod) % mod; }

ll cel(ll x1, ll y1) //not for negative x1
{
    if ((x1) <= 0)
    {
        return (x1) / (y1);
    }
    return (((x1) / (y1)) + (((x1) % (y1)) != 0));
}

bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a / gcd(a, b)) * b);
}

long long bp(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long bpm(long long a, long long b, long long m = mod1)
{
    if (a >= m)
        a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        if (res >= m)
            res %= m;
        a *= a;
        if (a >= m)
            a %= m;
        b >>= 1;
    }
    if (res >= m)
        res %= m;
    return res;
}

//constants

string vow = "aeiou";

const int dr4[] = {-1, 0, 1, 0};
const int dc4[] = {0, 1, 0, -1};

const int drk[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dck[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int drh[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dch[] = {1, -1, 2, -2, 2, -2, 1, -1};

const ll maxn = 2e5 + 5;
const ll inf = 1e9;
const ld PI = acos(-1);
const int imin = INT_MIN;
const int imax = INT_MAX;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
const ld dmin = DBL_MIN;
const ld dmax = DBL_MAX;

void solve(int tc)
{
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = x;
    if (n == 1)
    {
        cout << ans;
        R;
    }
    ll cur = (x * x) % m;
    vb vis(m, false);
    vis[cur] = true;
    int cnt = 1;
    vll cycle;
    cycle.push_back(cur);
    ll p = cur;
    ll cyclesum = cur;
    while (true)
    {
        ll nxt = (cur * cur) % m;
        if (vis[nxt])
        {
            p = nxt;
            break;
        }
        vis[nxt] = true;
        cnt++;
        cur = nxt;
        cycle.pb(cur);
        cyclesum += cur;
    }
    n--;
    if (n <= cycle.size())
    {
        p = (x * x) % m;
        while (n--)
        {
            ans += p;
            p = (p * p) % m;
        }
        cout << ans;
        R;
    }
    ans += cyclesum;
    n -= cycle.size();
    vis = vb(m, false);
    cycle.clear();
    cyclesum = 0;
    vis[p] = true;
    while (true)
    {
        cycle.pb(p);
        cyclesum += p;
        p = (p * p) % m;
        if (vis[p])
        {
            break;
        }
        else
            vis[p] = true;
    }
    ans += (cyclesum * (n / cycle.size()));
    n %= cycle.size();
    p = cycle[0];
    while (n--)
    {
        ans += p;
        p = (p * p) % m;
    }
    cout << ans;
}

int main()
{

    //read

    //write
    fast;
    int t = 1;
    //cin >> t;
    loop(i, 1, t)
    {

        solve(i);
        cout << "\n";
    }

    return 0;
}