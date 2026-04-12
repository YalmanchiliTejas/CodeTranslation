///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <typeinfo>
#include <numeric>
#include <cassert>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

#define DEBUG 0

#define pb push_back
#define V vector
#define M unordered_map

#define rep(i,n) for(ll i=0LL;i<n;++i)
#define srep(i,s,n) for(ll i=s;i<n;++i)
#define rrep(i,n) for(ll i=n-1LL;i>=0LL;--i)
#define ALL(a) (a).begin(),(a).end()
#define CIN(x) do { \
    assert(!cin.eof()); \
    cin >> x; \
    assert(!cin.fail()); \
} while(0);
#if DEBUG
#define debug_print(...) _debug_print(__VA_ARGS__)
#define debug_printf(...) printf(__VA_ARGS__)
#else // DEBUG
#define debug_print(...)
#define debug_printf(...)
#endif // DEBUG

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T>>;

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

struct BIT
{
    ll *tree;
    ll size;

    BIT(ll n, ll init) {
        tree = new ll[n+1];
        size = n;
        memset(tree, 0, sizeof(ll) * (n+1));
        this->init(init);
    }

    void init(ll init) {
        rep (i0, size) {
            ll idx = i0 + 1LL;
            while (idx <= size) {
                tree[idx] += init;
                idx += (idx & (-idx));
            }
        }
    }

    // idx is 1 origin
    void add(ll idx, ll x) {
        assert(idx > 0LL);
        while (idx <= size) {
            tree[idx] += x;
            idx += (idx & (-idx));
        }
    }

    // idx is 1 origin
    ll sum(ll idx) {
        assert(idx > 0LL);
        ll ret = 0LL;
        while (idx > 0LL) {
            ret += tree[idx];
            idx -= (idx & (-idx));
        }
        return ret;
    }
};

struct MaxFlow {
    V<ll> links[1005];
    ll capacities[1005][1005];
    ll nodes;

    MaxFlow(ll nodes) {
        // i == 0       --> S
        // i == nodes+1 --> T
        rep (i, nodes+2LL) links[i].clear();
        memset(capacities, 0, sizeof(capacities));
        this->nodes = nodes;
    }

    void add_path(ll a, ll b, ll capacity) {
        links[a].pb(b);
        links[b].pb(a);
        capacities[a][b] = capacity;
        capacities[b][a] = 0LL;
    }

    ll solve(void) {
        deque<V<ll>> q;
        ll ret = 0LL;

        for ( ; ; q.clear()) {

            V<ll> start;
            start.pb(0);
            q.push_front(start);

            bool checked[nodes+2];
            memset(checked, 0, sizeof(checked));

            V<ll> found;

            for ( ; !(q.empty()); ) {
                V<ll> path = q.front(); q.pop_front();
                ll last = path[path.size()-1];

                if (checked[last]) continue;
                if (last == nodes+1) {
                    found = path;
                    break;
                }

                checked[last] = true;
                for (auto next : (links[last])) {
                    if (capacities[last][next] == 0) continue;
                    V<ll> newpath(path);
                    newpath.pb(next);
                    q.push_front(newpath);
                }
            }

            if (found.size() == 0) {
                break;
            }
            else {
                ll flowcount = capacities[found[0]][found[1]];
                rep (i, found.size()-1) {
                    ll src = found[i];
                    ll dst = found[i+1];
                    flowcount = min(flowcount, capacities[src][dst]);
                }
                rep (i, found.size()-1) {
                    ll src = found[i];
                    ll dst = found[i+1];
                    capacities[src][dst] -= flowcount;
                    capacities[dst][src] += flowcount;
                }
                ret += flowcount;
            }
        }

        return ret;
    }
};

template <typename T>
struct SegmentTree {
    T *nodes;
    t2 *ranges;  // [start, end)
    ll nodecount;
    ll itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(ll itemcount, T unit, T op(T, T)) {
        ll orig_itemcount = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < orig_itemcount) this->itemcount *= 2LL;
        nodecount = this->itemcount * 2 - 1;
        nodes = new T[nodecount];
        ranges = new t2[nodecount];
        this->unit = unit;
        this->op = op;

        ll start = 0LL;
        ll end = this->itemcount;
        ll len = this->itemcount;

        rep (i, nodecount) {
            nodes[i] = unit;
            ranges[i] = t2(start, end);
            if (end >= this->itemcount) {
                len /= 2LL;
                start = 0LL;
                end = len;
            }
            else {
                start = end;
                end = start + len;
            }
        }
    }

    void update(ll k, T v) {
        ll idx = k + itemcount - 1LL;
        nodes[idx] = v;
        idx = (idx - 1LL) / 2LL;

        for ( ; idx >= 0; idx = (idx - 1LL) / 2LL) {
            nodes[idx] = op(nodes[idx * 2LL + 1LL],
                            nodes[idx * 2LL + 2LL]);
            if (!idx) break;
        }
    }

    T query(ll start, ll end) const {
        return _query(start, end, 0LL);
    }

    T _query(ll start, ll end, ll idx) const {
        ll rstart = get<0>(ranges[idx]);
        ll rend = get<1>(ranges[idx]);

        if (start <= rstart && rend <= end) {
            return nodes[idx];
        }
        if (rend <= start || end <= rstart) {
            return unit;
        }
        T left = _query(start, end, idx * 2LL + 1LL);
        T right = _query(start, end, idx * 2LL + 2LL);
        return op(left, right);
    }

};

void llin(ll &a)
{
    CIN(a);
}

void llinl1(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void llinl2(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void llinl3(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void llinl4(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
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

ll mod_mlt(ll x, ll y, ll mod)
{
    ll ret = 0LL;
    x %= mod;

    while (y) {
        if (y & 1LL) {
            ret += x;
            ret %= mod;
        }
        y >>= 1;
        x <<= 1;
        x %= mod;
    }

    return ret;
}

// O(log(exp))
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

// O(log(mod))
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

bool is_prime(ll x)
{
    V<ll> factors, factors2;

    get_factors(factors, x);

    for (auto factor : factors) {
        if (factor > 1) factors2.pb(factor);
    }

    return factors2.size() == 1 && x == factors2[0];
}

template <typename T>
void intersection(const set<T> &a, const set<T> &b,
                  set<T> &result)
{
    set_intersection(ALL(a), ALL(b), inserter(result, result.end()));
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

void make_linklist(const V<t2> &srclist, V<ll> dstlist[])
{
    for (auto src : srclist) {
        ll a = get<0>(src);
        ll b = get<1>(src);
        dstlist[a].pb(b);
        dstlist[b].pb(a);
    }
}

void make_parent(const V<ll> linklist[], ll root, ll n,
                 ll parent[], ll level[])
{
    queue<ll> q;
    bool checked[n+1];

    memset(checked, 0, sizeof(checked));

    q.push(root);
    checked[root] = true;
    parent[root] = root;
    level[root] = 0LL;

    for ( ; !(q.empty()); ) {
        ll now = q.front(); q.pop();
        for (auto next : linklist[now]) {
            if (checked[next]) continue;
            q.push(next);
            checked[next] = true;
            parent[next] = now;
            level[next] = level[now] + 1LL;
        }
    }
}

#define POW_ANCESTOR_MAXSIZE   20

// preprocess for get_common_ancestor()
void make_pow_ancestor(const ll parent[], ll n,
                       ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE])
{
    rep (i, n) pow_ancestor[i+1][0] = parent[i+1];

    for (int pow2 = 1; pow(2, pow2) <= n; ++pow2) {
        rep (i0, n) {
            int i = i0+1;
            ll prev = pow_ancestor[i][pow2-1];
            pow_ancestor[i][pow2] = pow_ancestor[prev][pow2-1];
        }
    }
}

ll get_common_ancestor(ll n, ll x, ll y,
                       const ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE],
                       const ll level[])
{
    if (level[x] < level[y]) {
        ll diff = level[y] - level[x];
        for ( ; diff; ) {
            ll bit = diff & -diff;
            y = pow_ancestor[y][(int)log2(bit)];
            diff -= bit;
        }
    }
    else {
        ll diff = level[x] - level[y];
        for ( ; diff; ) {
            ll bit = diff & -diff;
            x = pow_ancestor[x][(int)log2(bit)];
            diff -= bit;
        }
    }

    if (x == y) return x;

    rrep (i, (int)log2(n)+1) {
        if (pow_ancestor[x][i] != pow_ancestor[y][i]) {
            x = pow_ancestor[x][i];
            y = pow_ancestor[y][i];
        }
    }

    return pow_ancestor[x][0];
}

void kmp_init(const string &pattern, ll kmp_next[])
{
    kmp_next[0] = -1LL;

    ll plen = pattern.size();
    ll prefix_end = -1;

    rep (suffix_end, pattern.size()) {
        while (prefix_end >= 0 && pattern[suffix_end] != pattern[prefix_end]) {
            prefix_end = kmp_next[prefix_end];
        }
        kmp_next[suffix_end+1] = ++prefix_end;
    }

    kmp_next[0] = 0LL;
}

// founds ... list of text's idx of match position. start position idx.
void kmp_search(const string &text, const string &pattern, const ll kmp_next[],
                V<ll> &founds)
{
    ll text_size = text.size();
    ll pattern_size = pattern.size();
    ll text_start = 0LL;
    ll pattern_idx = 0LL;

    assert(pattern_size <= text_size);

    for ( ; ; ) {
        if (text_start + pattern_idx >= text_size) break;
        if (pattern_idx >= pattern_size) break;

        if (text[text_start+pattern_idx] == pattern[pattern_idx]) {
            pattern_idx++;
            if (pattern_idx == pattern_size) {
                founds.pb(text_start);
                pattern_idx = kmp_next[pattern_idx];
                text_start += (pattern_size - pattern_idx);
            }
        }

        else {
            text_start += (pattern_idx - kmp_next[pattern_idx]);
            pattern_idx = kmp_next[pattern_idx];
            if (pattern_idx == 0LL && text[text_start] != pattern[0]) {
                text_start++;
            }
        }
    }
}

void _debug_print(auto x)
{
    cout << x << endl;
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "-- " << x1 << " -- " << x2 << endl;
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "-- " << x1 << " -- " << x2 << " -- " << x3 << endl;
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "-- " << x1 << " -- " << x2
        << " -- " << x3 << " -- " << x4 << endl;
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename S, typename T>
void _debug_print(const M<S, T> &xlist)
{
    for (auto x : xlist) {
        S k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

int _main();
int main()
{
    cout << setprecision(12);
    return _main();
}

///////////////////////////////////////////////////////////////////////////////

ll inf = (ll)pow(10LL, 18LL);
ll mod = (ll)pow(10LL, 9LL) + 7LL;

void make_dlinklist(V<t2> dlinklist[], const V<t3> &uvdlist, ll n)
{
    for (auto uvd : uvdlist) {
        ll u = get<0>(uvd);
        ll v = get<1>(uvd);
        ll d = get<2>(uvd);
        dlinklist[u].pb(t2(v, d));
        dlinklist[v].pb(t2(u, d));
    }

    rep (i, n+1) {
        debug_printf("---- dlinklist %lld\n", i);
        debug_print(dlinklist[i]);
    }
}

void make_shortest_count(const V<t2> dlinklist[],
                         ll shortest[], ll count[], ll start, ll n)
{
    priority_queue_incr<t2> q;
    bool checked[n+1];
    rep (i, n + 1) {
        shortest[i] = inf;
        count[i] = 0LL;
        checked[i] = false;
    }

    shortest[start] = 0LL;
    count[start] = 1LL;
    q.push(t2(shortest[start], start));

    while (!q.empty()) {
        t2 cost_now = q.top(); q.pop();
        ll cost = get<0>(cost_now);
        ll now = get<1>(cost_now);

        if (checked[now]) continue;

        for (auto nextd : dlinklist[now]) {
            ll next = get<0>(nextd);
            ll d = get<1>(nextd);
            if (shortest[now] + d > shortest[next]) continue;
            if (shortest[now] + d == shortest[next]) {
                count[next] += count[now];
                count[next] %= mod;
                continue;
            }
            shortest[next] = shortest[now] + d;
            count[next] = count[now];
            q.push(t2(shortest[next], next));
        }

        checked[now] = true;
    }

    rep (i, n+1) debug_printf("---- %lld --> %lld: shorest=%lld count=%lld\n",
                              start, i, shortest[i], count[i]);
}

void make_nodes_in_paths(V<ll> &nodes_in_paths, bool nodes_in_paths_flag[],
                         ll shortest_cost,
                         const ll shortest_s[], const ll shortest_t[], ll n)
{
    memset(nodes_in_paths_flag, 0, sizeof(bool) * (n + 1));

    rep (i0, n) {
        ll i = i0 + 1LL;
        if (shortest_s[i] + shortest_t[i] == shortest_cost) {
            nodes_in_paths.pb(i);
            nodes_in_paths_flag[i] = true;
        }
    }

    debug_printf("---- nodes_in_paths\n"); debug_print(nodes_in_paths);
    rep (i, n+1) {
        debug_printf("---- nodes_in_paths_flag %lld = %d\n", i, nodes_in_paths_flag[i]);
    }
}

bool is_halfway(ll cost_a, ll cost_b, ll shortest_cost)
{
    if (cost_a * 2LL == shortest_cost) return false;
    if (cost_b * 2LL == shortest_cost) return false;
    if (cost_a * 2LL < shortest_cost && shortest_cost < cost_b * 2LL) {
        return true;
    }
    if (cost_b * 2LL < shortest_cost && shortest_cost < cost_a * 2LL) {
        return true;
    }

    return false;
}

void find_halfway(V<ll> &halfway_v, V<t2> &halfway_e, const V<t2> dlinklist[],
                  const V<ll> &nodes_in_paths, const bool nodes_in_paths_flag[],
                  ll shortest_cost,
                  const ll shortest_s[], const ll shortest_t[], ll n)
{
    rep (i0, n) {
        ll i = i0 + 1LL;
        if (shortest_s[i] == shortest_t[i]) halfway_v.pb(i);
    }

    for (auto node : nodes_in_paths) {
        for (auto nextd : dlinklist[node]) {
            ll next = get<0>(nextd);
            ll d = get<1>(nextd);

            if (node > next) continue;

            if (!nodes_in_paths_flag[next]) continue;
            if (shortest_s[node] + d != shortest_s[next] &&
                shortest_t[node] + d != shortest_t[next]) continue;

            if (is_halfway(shortest_s[node], shortest_s[next], shortest_cost)) {
                t2 val;
                if (shortest_s[node] < shortest_s[next]) val = t2(node, next);
                else val = t2(next, node);
                halfway_e.pb(val);
            }
        }
    }

    debug_printf("---- halfway_v\n"); debug_print(halfway_v);
    debug_printf("---- halfway_e\n"); debug_print(halfway_e);
}

int _main()
{
    ll n; llin(n);
    ll m; llin(m);
    ll s; llin(s);
    ll t; llin(t);
    V<t3> uvdlist; llinl3(uvdlist, m);

    V<t2> dlinklist[n+1];
    make_dlinklist(dlinklist, uvdlist, n);

    ll shortest_s[n+1], count_s[n+1];
    make_shortest_count(dlinklist, shortest_s, count_s, s, n);
    ll shortest_t[n+1], count_t[n+1];
    make_shortest_count(dlinklist, shortest_t, count_t, t, n);

    assert(shortest_s[t] == shortest_t[s]);
    assert(count_s[t] == count_t[s]);

    ll shortest_cost = shortest_s[t];

    V<ll> nodes_in_paths;
    bool nodes_in_paths_flag[n+1];
    make_nodes_in_paths(nodes_in_paths, nodes_in_paths_flag, shortest_cost,
                        shortest_s, shortest_t, n);

    V<ll> halfway_v;
    V<t2> halfway_e;
    find_halfway(halfway_v, halfway_e,
                 dlinklist, nodes_in_paths, nodes_in_paths_flag,
                 shortest_cost, shortest_s, shortest_t, n);

    ll ans = 1LL;
    ans *= count_s[t];
    ans *= count_t[s];
    ans %= mod;
    debug_printf("---- ans 1 = %lld\n", ans);

    for (auto v : halfway_v) {
        ll decr = 1LL;
        decr *= count_s[v];
        decr %= mod;
        decr *= count_s[v];
        decr %= mod;
        decr *= count_t[v];
        decr %= mod;
        decr *= count_t[v];
        decr %= mod;
        debug_printf("halfway_v v=%lld decr=%lld\n", v, decr);
        ans -= decr;
        while (ans < 0LL) ans += mod;
    }

    for (auto e : halfway_e) {
        ll v_s = get<0>(e);
        ll v_t = get<1>(e);
        ll decr = 1LL;
        decr *= count_s[v_s];
        decr %= mod;
        decr *= count_s[v_s];
        decr %= mod;
        decr *= count_t[v_t];
        decr %= mod;
        decr *= count_t[v_t];
        decr %= mod;
        debug_printf("halfway_e %lld<-->%lld decr=%lld\n", v_s, v_t, decr);
        ans -= decr;
        while (ans < 0LL) ans += mod;
    }

    cout << ans % mod;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
