#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define ar array
#define deb(x) cout << #x << " = " << x << endl
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const ll MAX = 2e5 + 1;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
inline ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
inline ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
struct comp
{
    bool operator()(const pair<ll, ll> &x, const pair<ll, ll> &y) const
    {
        return x.first < y.first;
    }
};
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll pwr(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n & 1)
        return mul(x, pwr(mul(x, x), (n - 1) / 2));
    else
        return pwr(mul(x, x), n / 2);
}
ll modInv(ll n)
{
    return pwr(n, mod - 2);
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
ll a[4000];
int main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n + 1];
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                pref[i] = a[i];
            else
                pref[i] = pref[i - 1] + a[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll diff = pref[n - 1] - pref[i];
            ans = add(ans, mul(a[i], diff));
        }
        cout << ans << endl;
    }
}