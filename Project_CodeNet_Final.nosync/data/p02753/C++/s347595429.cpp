#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#define sd(n) scanf("%d", &n)
#define sdd(n, m) scanf("%d%d", &n, &m)
#define sddd(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define pd(n) printf("%d\n", n)
#define pc(n) printf("%c", n)
#define pdd(n, m) printf("%d %d\n", n, m)
#define pld(n) printf("%lld\n", n)
#define pldd(n, m) printf("%lld %lld\n", n, m)
#define sld(n) scanf("%lld", &n)
#define sldd(n, m) scanf("%lld%lld", &n, &m)
#define slddd(n, m, k) scanf("%lld%lld%lld", &n, &m, &k)
#define sf(n) scanf("%lf", &n)
#define sc(n) scanf("%c", &n)
#define sff(n, m) scanf("%lf%lf", &n, &m)
#define sfff(n, m, k) scanf("%lf%lf%lf", &n, &m, &k)
#define ss(str) scanf("%s", str)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define mem(a, n) memset(a, n, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mod(x) ((x) % MOD)
#define gcd(a, b) __gcd(a, b)
#define lowbit(x) (x & -x)
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
inline int read()
{
    int ret = 0, sgn = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * sgn;
}
inline void Out(int a) //ê?3?ía1ò
{
    if (a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
///快速幂m^k%mod
ll qpow(ll x, ll n, ll mod)
{
    if (n == 0)
        return 1;
    ll res = qpow((x * x) % mod, n / 2, mod) % mod;
    if (n & 1)
        res = (res * x) % mod;
    return res % mod;
}
// 快速幂求逆元
int Fermat(int a, int p) //费马求a关于b的逆元
{
    return qpow(a, p - 2, p);
}

///扩展欧几里得
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return g;
}

int n, m, k;
int res, cnt, ans;
const int N = 4e5 + 10;
string s;

int main()
{
    cin >> s;
    int cnt1 = 0;
    int cnt2 = 0;
    rep(i, 0, 2)
    {
        if (s[i] == 'A')
            cnt1++;
        else
            cnt2++;
    }
    if (cnt1 &&cnt2 )
        puts("Yes");
    else
        puts("No");
    return 0;
}