///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
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
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

struct UnionFind
{
        ull *parent, *count, *rank;

        UnionFind(ull n) {
                parent = new ull[n+1];
                count = new ull[n+1];
                rank = new ull[n+1];
                for (ull i = 0ULL; i < n+1; ++i) {
                        parent[i] = i;
                        count[i] = 1;
                        rank[i] = 0;
                }
        }

        ull root(ull i) {
                if (parent[i] == i) return i;
                parent[i] = root(parent[i]);
                return parent[i];
        }

        void unite(ull i, ull j) {
                ull rooti = root(i);
                ull rootj = root(j);

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

        bool same(ull i, ull j) {
                return root(i) == root(j);
        }
};

void llin(ll &a)
{
        cin >> a;
}

void llinl1(auto &v, ll count)
{
        for (ll i = 0LL; i < count ; ++i) {
                ll a;
                cin >> a;
                v.push_back(a);
        }
}

void llinl2(auto &v, ll count)
{
        for (ll i = 0LL; i < count ; ++i) {
                ll a, b;
                cin >> a >> b;
                v.push_back(tuple<ll, ll>(a, b));
        }
}

void llinl3(auto &v, ll count)
{
        for (ll i = 0LL; i < count ; ++i) {
                ll a, b, c;
                cin >> a >> b >> c;
                v.push_back(tuple<ll, ll, ll>(a, b, c));
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

ll absll(ll x)
{
        if (x < 0) return -x;
        return x;
}

ll mod_pow(ll base, ll exp, ll mod)
{
        ll ret = 1LL;

        for ( ; exp; ) {
                if (exp & 1LL) {
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
        return mod_pow(x, mod - 2LL, mod);
}

ll gcm(ll x, ll y)
{
        while (y != 0) {
                ll z = x % y;
                x = y;
                y = z;
        }
        return x;
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
        for (ll i = 1LL; i < sqrt(x) + 3LL; ++i) {
                if (x % i == 0LL) {
                        retlist.push_back(i);
                        retlist.push_back(x / i);
                }
        }
}

void get_factors(V<ll> &retlist, ll x)
{
        for (ll i = 2LL; i < (ll)(sqrt(x)) + 3LL; ++i) {
                while (x % i == 0LL) {
                        retlist.pb(i);
                        x /= i;
                }
        }
        retlist.pb(x);
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

ull combination(ll x, ll y)
{
        if (y > x / 2LL) y = x - y;

        ull ret = 1LL;
        for (ll i = 0LL; i < y; ++i) {
                ret *= x--;
                ret /= (i + 1LL);
        }

        return ret;
}

ull mod_combination(ll x, ll y, ll mod)
{
        if (y > x / 2LL) y = x - y;

        ll ret = 1;

        for (ll i = 0LL; i < y; ++i) {
                ret = (ret * x--) % mod;
                ret = (ret * mod_inv(i + 1LL, mod)) % mod;
        }

        return ret;
}

void make_linklist(const V<tuple<ll, ll>> &srclist, V<V<ll>> &dstlist)
{
        for (auto src : srclist) {
                ll a = get<0>(src);
                ll b = get<1>(src);
                dstlist[a].pb(b);
                dstlist[b].pb(a);
        }
}

void debug_print(auto xlist)
{
        for (auto x : xlist) cout << "-- " << x << endl;
}

int _main();
int main()
{
        cout << setprecision(12);
        return _main();
}

///////////////////////////////////////////////////////////////////////////////

ll mod = pow(10LL, 9LL) + 7LL;

int _main()
{
        ll n, m, k;
        llin(n); llin(m); llin(k);

        ll count = 0;

        rep (i, m) {
                ll tmp;
                tmp = ((m - i) * n) % mod;
                tmp = (tmp * n) % mod;
                tmp = (tmp * i) % mod;
                count += tmp;
                count %= mod;
        }

        rep (i, n) {
                ll tmp;
                tmp = ((n - i) * m) % mod;
                tmp = (tmp * m) % mod;
                tmp = (tmp * i) % mod;
                count += tmp;
                count %= mod;
        }

        ll ans = mod_combination(n * m - 2, k - 2, mod);
        ans = (ans * count) % mod;
        cout << ans;

        return 0;
}

///////////////////////////////////////////////////////////////////////////////
