///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <typeinfo>
#include <numeric>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

#define pb push_back
#define V vector
#define M unordered_map
#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)

struct UnionFind
{
        unsigned ll *parent, *count, *rank;

        UnionFind(unsigned ll n) {
                parent = new unsigned ll[n+1];
                count = new unsigned ll[n+1];
                rank = new unsigned ll[n+1];
                for (unsigned ll i = 0UL; i < n+1; ++i) {
                        parent[i] = i;
                        count[i] = 1;
                        rank[i] = 0;
                }
        }

        unsigned ll root(unsigned ll i) {
                if (parent[i] == i) return i;
                parent[i] = root(parent[i]);
                return parent[i];
        }

        void unite(unsigned ll i, unsigned ll j) {
                unsigned ll rooti = root(i);
                unsigned ll rootj = root(j);

                if (rooti == rootj) return;

                if (rank[rootj] < rank[rooti]) {
                        parent[i] = parent[j] = parent[rootj] = rooti;
                        count[rooti] += count[rootj];
                }
                else {
                        parent[i] = parent[j] = parent[rooti] = rootj;
                        count[rootj] += count[rooti];
                        if (rank[rootj] == rank[rooti]) rank[rootj]++;
                }
        }

        bool same(unsigned ll i, unsigned ll j) {
                return root(i) == root(j);
        }
};

struct T2 {
        ll t0;
        ll t1;
};

struct T3 {
        ll t0;
        ll t1;
        ll t2;
};

struct T4 {
        ll t0;
        ll t1;
        ll t2;
        ll t3;
};

bool operator<(const T2 &lhs, const T2 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 < rhs.t0;
        return lhs.t1 < rhs.t1;
}

bool operator>(const T2 &lhs, const T2 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 > rhs.t0;
        return lhs.t1 > rhs.t1;
}

bool operator==(const T2 &lhs, const T2 &rhs)
{
        if (lhs.t0 != rhs.t0) return false;
        return lhs.t1 == rhs.t1;
}

bool operator!=(const T2 &lhs, const T2 &rhs)
{
        return !(lhs == rhs);
}

bool operator<(const T3 &lhs, const T3 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 < rhs.t0;
        if (lhs.t1 != rhs.t1) return lhs.t1 < rhs.t1;
        return lhs.t2 < rhs.t2;
}

bool operator>(const T3 &lhs, const T3 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 > rhs.t0;
        if (lhs.t1 != rhs.t1) return lhs.t1 > rhs.t1;
        return lhs.t2 > rhs.t2;
}

bool operator==(const T3 &lhs, const T3 &rhs)
{
        if (lhs.t0 != rhs.t0) return false;
        if (lhs.t1 != rhs.t1) return false;
        return lhs.t2 == rhs.t2;
}

bool operator!=(const T3 &lhs, const T3 &rhs)
{
        return !(lhs == rhs);
}

bool operator<(const T4 &lhs, const T4 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 < rhs.t0;
        if (lhs.t1 != rhs.t1) return lhs.t1 < rhs.t1;
        if (lhs.t2 != rhs.t2) return lhs.t2 < rhs.t2;
        return lhs.t3 < rhs.t3;
}

bool operator>(const T4 &lhs, const T4 &rhs)
{
        if (lhs.t0 != rhs.t0) return lhs.t0 > rhs.t0;
        if (lhs.t1 != rhs.t1) return lhs.t1 > rhs.t1;
        if (lhs.t2 != rhs.t2) return lhs.t2 > rhs.t2;
        return lhs.t3 > rhs.t3;
}

bool operator==(const T4 &lhs, const T4 &rhs)
{
        if (lhs.t0 != rhs.t0) return false;
        if (lhs.t1 != rhs.t1) return false;
        if (lhs.t2 != rhs.t2) return false;
        return lhs.t3 == rhs.t3;
}

bool operator!=(const T4 &lhs, const T4 &rhs)
{
        return !(lhs == rhs);
}

void llin(ll &a)
{
        cin >> a;
}

void llinl1(auto &v, ll count)
{
        for (ll i = 0; i < count ; ++i) {
                ll a;
                cin >> a;
                v.push_back(a);
        }
}

void llinl2(auto &v, ll count)
{
        for (ll i = 0; i < count ; ++i) {
                ll a, b;
                cin >> a >> b;
                v.push_back({a, b});
        }
}

void llinl3(auto &v, ll count)
{
        for (ll i = 0; i < count ; ++i) {
                ll a, b, c;
                cin >> a >> b >> c;
                v.push_back({a, b, c});
        }
}

void llina(auto &v, ll count)
{
        llinl1(v, count);
}

template <typename T>
T min(const V<T> v)
{
        T ret = v[0];
        for (auto i : v) ret = min(ret, i);
        return ret;
}

template <typename T>
T max(const V<T> v)
{
        T ret = v[0];
        for (auto i : v) ret = max(ret, i);
        return ret;
}

ll mod_pow(ll base, ll exp, ll mod)
{
        ll ret = 1;

        for ( ; exp; ) {
                if (exp & 1) {
                        ret *= base;
                        ret %= mod;
                }
                base = (base * base) % mod;
                exp >>= 1;
        }

        return ret;
}

ll mod_inv(ll x, ll mod)
{
        // available only when mod is prime
        return mod_pow(x, mod - 2, mod);
}

template <typename T>
void sort(V<T> &v)
{
        sort(v.begin(), v.end());
}

template <typename T>
void sort_reverse(V<T> &v)
{
        sort(v.begin(), v.end(), greater<T>());
}

void get_divisors(V<ll> &retlist, ll x)
{
        for (int i = 1; i < sqrt(x) + 3; ++i) {
                if (x % i == 0) {
                        retlist.push_back(i);
                        retlist.push_back(x / i);
                }
        }
}

template <typename T>
void intersection(const set<T> &a, const set<T> &b,
                  set<T> &result)
{
        V<T> resultlist;

        set_intersection(a.begin(), a.end(),
                         b.begin(), b.end(),
                         back_inserter(resultlist));

        set<T> resultset(resultlist.begin(), resultlist.end());
        result = resultset;
}

unsigned ll combination(ll x, ll y)
{
        if (y > x / 2L) y = x - y;

        unsigned ll ret = 1;
        for (int i = 0; i < y; ++i) {
                ret *= x--;
                ret /= (i + 1);
        }

        return ret;
}

void make_linklist(const V<T2> &srclist, V<V<ll>> &dstlist)
{
        for (T2 src : srclist) {
                ll a = src.t0;
                ll b = src.t1;
                dstlist[a].pb(b);
                dstlist[b].pb(a);
        }
}

void debug_print(auto xlist)
{
        for (auto x : xlist) cout << "-- " << x << endl;
}

///////////////////////////////////////////////////////////////////////////////

ll center[51];
ll counts[51];
ll pcounts[51];

ll f(ll i, ll x)
{
        //cout << "i=" << i << " x=" << x << " center=" << center[i] << endl;

        if (i == 0) return x & 1;

        if (x == 0) return 0;
        if (x < center[i] + 1) {
                return f(i - 1, x - 1);
        }
        if (x == center[i] + 1) {
                return f(i - 1, x - 2) + 1;
        }
        if (x < counts[i]) {
                return pcounts[i-1] + 1 + f(i - 1, x - (center[i] + 1));
        }

        return pcounts[i-1] + 1 + f(i - 1, x - (center[i] + 1) - 1);
}

int main()
{
        ll n, x;
        llin(n); llin(x);

        center[0] = 0;
        counts[0] = 1;
        pcounts[0] = 1;
        rep (i, n) {
                center[i+1] = counts[i] + 1;
                counts[i+1] = counts[i] * 2 + 3;
                pcounts[i+1] = pcounts[i] * 2 + 1;
        }

        cout << f(n, x);

        return 0;
}

///////////////////////////////////////////////////////////////////////////////
