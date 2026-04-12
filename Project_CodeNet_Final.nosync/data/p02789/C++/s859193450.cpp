#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pll = pair<ll, ll>;
using pss = pair<string, string>;
using pdd = pair<ld, ld>;
using graph = vector<vector<int>>;

const ll MOD = 1000000007;
const ld EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ex[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ey[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }

ll intabs(ll a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}

ll intpow(ll a, ll b, ll p = LLONG_MAX)
{
    ll ret = 1;
    while (b != 0)
    {
        if ((b & 1) == 1)
            ret *= a;
        a *= a;
        if (a >= p)
            a %= p;
        if (ret >= p)
            ret %= p;
        b = b >> 1;
    }
    return ret;
}

int digit(ll a, ll b = 10)
{
    int ret = 0;
    while (a != 0)
    {
        a /= b;
        ret++;
    }
    return ret;
}

ll gcd(ll x, ll y)
{
    while (y != 0)
    {
        ll cnt = x % y;
        x = y;
        y = cnt;
    }
    return x;
}

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

class UnionFind
{
    vector<int> par, sz;

public:
    UnionFind(int n) : par(n), sz(n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
        sz[ry] += sz[rx];
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x)
    {
        return sz[root(x)];
    }
};

vector<bool> seen;
void dfs(const graph &g, int v)
{
    seen[v] = true;
    for (auto i : g[v])
    {
        if (seen[i])
            continue;
        dfs(g, i);
    }
}

int main()
{
    int i, j, k, cnt;
    int n, m;
    cin >> n >> m;
    if (n == m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}