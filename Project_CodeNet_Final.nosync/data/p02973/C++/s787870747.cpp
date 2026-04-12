#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
#define PI (acos(-1))
#define ALL(c) (c).begin(), (c).end()

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

bool is_prime(ll x)
{
    if (x == 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod)
{
    return modpow(a, mod - 2, mod);
}

const ll MAX = 5100000;
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

struct BIT
{
    int n;
    vector<int> bit;
    BIT()
    {
        init();
    }
    BIT(int n) : n(n)
    {
        init();
    }
    void init()
    {
        bit.clear();
        bit.resize(n + 1, 0);
    }
    int sum(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    int sum(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    void add(int i, int x)
    {
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    int lower_bound(int w)
    {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1)
        {
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};
// 文字列t　->整数　atoi(t.c_str());
// 文字列t　->long long整数　stoll(t); ローカルではつかえない

struct LazySegmentTree
{
    // private:
    ll n;
    vector<ll> node, lazy;

    // public:
    LazySegmentTree(vector<ll> v)
    {
        int sz = (int)v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r)
    {
        if (lazy[k] != 0)
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        eval(k, l, r);
        if (b <= l || r <= a)
            return 0;
        if (a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

ll digit_sum(ll v)
{
    ll ret = 0;
    while (v)
    {
        ret += (v % 10);
        v /= 10;
    }
    return ret;
}

template <typename T>
struct Kruskal
{

    struct edge
    {
        ll from, to;
        T cost;
        ll used;
        edge() {}
        edge(ll from, ll to, T cost) : from(from), to(to), cost(cost), used(0) {}
        bool operator<(const edge &e) const
        {
            return cost < e.cost;
        }
    };

    ll n;
    vector<ll> p, r;
    vector<edge> edges;

    Kruskal() {}
    Kruskal(ll n) : n(n) {}

    void init(ll n)
    {
        r.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    ll find(ll x)
    {
        return (x == p[x] ? x : p[x] = find(p[x]));
    }

    bool same(ll x, ll y)
    {
        return find(x) == find(y);
    }

    void unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (r[x] < r[y])
            swap(x, y);
        r[x] += r[y];
        p[y] = x;
    }

    void add_edge(ll u, ll v, T c)
    {
        edges.emplace_back(u, v, c);
    }

    T build()
    {
        sort(edges.begin(), edges.end());
        init(n);
        T res = 0;
        for (auto &e : edges)
        {
            if (!same(e.from, e.to))
            {
                res += e.cost;
                unite(e.from, e.to);
                e.used = 1;
            }
        }
        return res;
    }
};

int LIS(int a[], int n)
{
    vector<int> A(n, 0x3f3f3f3f);
    for (int i = 0; i < n; i++)
        *lower_bound(A.begin(), A.end(), a[i]) = a[i];
    return find(A.begin(), A.end(), 0x3f3f3f3f) - A.begin();
}

// string maze[1010];
// ll maze[100][100];
// ll bfs(ll H, ll W, ll sx, ll sy, ll gx, ll gy)
// {

//     int dx[4] = {1, 0, -1, 0};
//     int dy[4] = {0, 1, 0, -1};

//     vector<vector<ll>> dist(H, vector<ll>(W, -1));
//     dist[sy][sx] = 0;

//     queue<PL> q;
//     q.push({sy, sx});
//     while (!q.empty())
//     {
//         ll x, y;
//         tie(y, x) = q.front();
//         q.pop();
//         if (y == gy && x == gx)
//         {
//             break;
//         }
//         for (int t = 0; t < 4; t++)
//         {
//             ll nx = x + dx[t], ny = y + dy[t];
//             if (nx < 0 || ny < 0 || nx >= W || ny >= H || dist[ny][nx] != -1 || maze[ny][nx] == '#')
//             {
//                 continue;
//             }

//             dist[ny][nx] = dist[y][x] + 1;
//             q.push({ny, nx});
//         }
//     }

//     return dist[gy][gx];
// }

vector<vector<ll>> warshall_floyd(ll n, vector<vector<ll>> g, ll INF)
{
    //init vector<vector<ll>> c(10,vector<ll>(10,0));

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][k] == INF || g[k][j] == INF)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    return g;
}

struct Dijkstra
{

    ll n;
    vector<vector<pair<ll, ll>>> Edges;
    vector<ll> Dist;
    vector<ll> Prev;
    vector<ll> PathNum;

    Dijkstra(ll n) : n(n), Edges(n), Dist(n), Prev(n), PathNum(n)
    {
        Prev.assign(n, -1);
    };

    void add_edge(ll a, ll b, ll c, bool directed = true)
    {
        if (directed)
        {
            Edges[a].emplace_back(make_pair(b, c));
        }
        else
        {
            Edges[a].emplace_back(make_pair(b, c));
            Edges[b].emplace_back(make_pair(a, c));
        }
    }
    // O((E+V)logV)
    void build(int start)
    {
        priority_queue<P, vector<P>, greater<P>> queue;
        fill(Dist.begin(), Dist.end(), 1e+18); //1e18 !?!?
        Dist[start] = 0;
        PathNum[start] = 1;
        queue.push(PL(0, start));

        while (!queue.empty())
        {
            PL p = queue.top();
            queue.pop();
            int v = p.second;
            if (Dist[v] < p.first)
                continue;

            for (int i = 0; i < Edges[v].size(); i++)
            {
                PL e = Edges[v][i];
                if (Dist[e.first] > Dist[v] + e.second)
                {
                    Dist[e.first] = Dist[v] + e.second;
                    queue.push(P(Dist[e.first], e.first));

                    Prev[e.first] = v;

                    PathNum[e.first] = PathNum[v];
                }
                else if (Dist[e.first] == Dist[v] + e.second)
                {
                    PathNum[e.first] += PathNum[v];
                    PathNum[e.first] %= MOD;
                }
            }
        }
    }

    ll dist(ll t)
    {
        return Dist[t];
    }

    vector<ll> get_path(ll t)
    {
        vector<ll> path;
        for (; t != -1; t = Prev[t])
        {
            path.push_back(t);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    ll get_path_num(ll t)
    {
        return PathNum[t];
    }

    // int solve()
    // {
    //    ll v, e, r;
    //    cin >> v >> e >> r;
    //    Dijkstra dij(v);
    //    for (int i = 0; i < e; i++)
    //    {
    //       ll a, b, c;
    //       cin >> a >> b >> c;
    //       dij.add_edge(a, b, c);
    //    }
    //    dij.build(r);
    //    for (int i = 0; i < v; i++)
    //    {
    //       if (dij.dist(i) == 1e18)
    //       {
    //          cout << "INF" << endl;
    //       }
    //       else
    //       {
    //          cout << dij.dist(i) << endl;
    //          cout << dij.get_path(i) << endl;
    //          cout << dij.get_path_num(i) << endl;
    //       }
    //    }
    //    return 0;
    // }
};

/*------------------------------*/

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
   for (auto &v : vec)
      is >> v;
   return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
   os << "[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
   os << "deq[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
   os << "(" << pa.first << "," << pa.second << ")";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
};
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
   fill((T *)array, (T *)(array + N), val);
}

ll a[101010];
ll solve()
{
    ll n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    multiset<ll> m;
    m.insert(a[0]);
    for(int i=1; i < n; i++){
        auto it = m.lower_bound(a[i]);
        if(it != m.begin()){
            it--;
            m.erase(it);
        }
        m.insert(a[i]);
    }
    cout << m.size() << endl;

    return 0;
}

int main()
{
    // cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
