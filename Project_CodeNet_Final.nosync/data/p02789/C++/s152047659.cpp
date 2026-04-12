
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ll long long
#define ld long double
#define MOD 1000000007
#define nl cout << bl
#define rt ll Q[100005] = {0}
#define mp make_pair
#define test() \
    ull t;     \
    cin >> t;  \
    while (t--)
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define s(ar, n) sort(ar, ar + n)
#define rs(ar, n) sort(ar, ar + n, greater<ll>())
#define oa(a, n)               \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << " ";
#define cn(a, n)               \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define ov(a, n)                    \
    for (ll i = n - 1; i >= 0; i--) \
        cout << a[i] << " ";        \
    nl
#define ovp(a, n)              \
    for (ll i = 0; i < n; i++) \
        cout << a[i].ff << " " << a[i].ss << bl;
#define maxa(ar, N) *max_element(ar, ar + N)
#define mina(ar, N) *min_element(ar, ar + N)
#define present(c, x) ((c).find(x) != (c).end())
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
typedef pair<int, int> pii;
ll fast_exp(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res % MOD;
}
ll fib(ll n)
{
    if (n < 2)
        return n;
    ll a = 0, b = 1, pre;
    int i = 1;
    while (i < n)
    {
        pre = (a + b) % MOD;
        a = b;
        b = pre;
        i++;
    }
    return pre;
}
ll fac(ll n)
{
    if (n % 2 == 0)
        return 2;

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }

    return n;
}
ll fact(ll n)
{
    if (n > 1)
        return n * fact(n - 1);
    else
        return 1;
}
bool sortbysec(const tuple<int, int, int> &a,
               const tuple<int, int, int> &b)
{
    return (get<1>(a) < get<1>(b));
}

int main()
{
    ll n, m;
    cin >> n >> m;
    if (n == m)
        cout << "Yes";
    else
        cout << "No";
}