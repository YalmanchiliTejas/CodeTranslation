#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mem(a, s) memset(a, s, sizeof(a))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
#define MAX 8000000000000000064LL
#define MIN -8000000000000000064LL
typedef vector<int> vi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;
const int mod = 1e9 + 7;
ll add(ll a, ll b) { return (a % mod + b % mod + ((MAX) / mod) * mod) % mod; }
ll sub(ll a, ll b) { return (a % mod - b % mod + ((MAX) / mod) * mod) % mod; }
ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod) + ((MAX) / mod) * mod) % mod;
}
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll fact[1000007] = {0};
ll expo(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (1ll * res * x) % mod;
        y = y >> 1;
        x = (1ll * x * x) % mod;
    }
    return res;
}
void facto() {
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < 1000007; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
ll ncr(ll n, ll r) {
    ll res = 1;
    res = fact[n];
    res = (res * (expo(fact[r], mod - 2))) % mod;
    res = (res * (expo(fact[n - r], mod - 2))) % mod;
    return res;
}
ll npr(ll n, ll r) {
    facto();
    ll res = 1;
    res = fact[n];
    res = (res * (expo(fact[n - r], mod - 2))) % mod;
    return res;
}
int _x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int _y[] = {-1, 1, 0, 0, 1, -1, -1, 1};
void solve();
void pre();
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t = 1;
    // cin >> t;
    rep(i, 1, t) { solve(); }
    return 0;
}

const int mxn = 1e5 + 10;
int vis[mxn] = {};
int ans[mxn] = {};

void pre() {}
void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    x %= m;
    ans[1] = x;
    vis[x] = 1;
    int r = -1, d;
    rep(i, 2, n) {
        x = x * x % m;
        ans[i] = ans[i - 1] + x;
        if (vis[x]) {
            r = vis[x];
            d = i - vis[x];
            break;
        }
        vis[x] = i;
    }
    if (r == -1)
        cout << ans[n] << '\n';
    else {
        int f = (n - r) / d, rr = (n - r) % d;
        cout << ans[r + rr] + (ans[r + d] - ans[r]) * f << '\n';
    }
}