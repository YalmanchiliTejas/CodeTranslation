/*Bismillahir Rahmanir Rahim*///{
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1;
const double eps = 1e-6, ldeps = 1e-9;
struct Dbg {
static constexpr auto &os = cout;   // replace by cerr in interactive.
template<class C> static auto dud(C *x)->decltype(os << *x, 0);
template<class C> static char dud(...);
template<class C> typename enable_if<sizeof dud<C>(0)!=1, Dbg&>::type operator<<(const C &x) { os << x; return *this; }
template<class C> Dbg &dump(C b, C e) {
    *this << "\n[";
    int cur = 0;
    for (C i = b; i!=e and cur<26; i++, cur++) *this << ", "+2*(i==b) << *i;
    return *this << ']';
}
template<class C> typename enable_if<sizeof dud<C>(0)==1, Dbg&>::type operator<<(const C &x) {
    return dump(begin(x), end(x));
}
template<class C, size_t X> typename enable_if<sizeof(C)!=1, Dbg&>::type operator <<(C (&x)[X]) {
    return dump(begin(x), end(x));
}
template<class B, class C> Dbg &operator <<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
}
template<class C, size_t Y> struct TP {
    void operator()(Dbg& os, const C &t) { TP<C, Y-1>()(os, t); os << ", " << get<Y-1>(t); }
};
template<class C> struct TP<C, 1> { void operator()(Dbg& os, const C &t) { os << get<0>(t); } };
template<class... C> Dbg& operator<<(const tuple<C...> &t) {
    os << '{', TP<decltype(t), sizeof...(C)>()(*this, t); return *this << '}';
}
Dbg &operator<<(ostream&(*x)(std::ostream&)) { os << x; return *this; }
} dbg;
void err(istringstream *iss) { delete iss; }
template<class C, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args ...);
}
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(string(#args)), args), dbg << endl
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
int T, Q, cn;//}
const int inf = 1000000007, mxn = 100005;

struct Int// Make sure to not do any operation with non-modded(except *, which must be int)//{
{
    int x;
    operator int() { return x; }
    Int() = default;
    Int(const int &rs) : x(rs) {};
    Int operator -() { return inf-*this; }
    Int operator ~() = delete;
    // Int operator ~() { return power(*this, inf-2); }
    Int operator +(const Int &rs) const { return x+rs.x>=inf ? x+rs.x-inf : x+rs.x; }
    Int operator -(const Int &rs) const { return x-rs.x<0 ? x-rs.x+inf : x-rs.x; }
    Int operator *(const Int &rs) const { return int(x*ll(rs.x)%inf); }
    Int operator <<(const int &rs) { return rs==1 ? *this+*this : *this*Int{1<<rs}; }
    Int& operator <<=(const int &rs) { return *this = *this<<rs; }
    Int& operator >>=(const int &rs) { return x>>=rs, *this; }  // only for power()
    Int& operator +=(const Int &rs) { return *this = *this+rs; }
    Int& operator -=(const Int &rs) { return *this = *this-rs; }
    Int& operator *=(const Int &rs) { return *this = *this*rs; }
    Int& operator ++() { return *this += 1; }
    Int operator ++(int) { return Int(x++); }
    Int& operator --() { return *this -= 1; }
    Int operator --(int) { return Int(x--); }
    friend istream& operator >>(istream &is, Int &rs) { return is>>rs.x; }
    friend ostream& operator <<(ostream &os, const Int &rs) { return os<<rs.x; }
    friend Int operator +(const Int &ls, const int &rs) { return ls+Int(rs); }
    friend Int operator +(const int &ls, const Int &rs) { return Int(ls)+rs; }
    friend Int operator -(const Int &ls, const int &rs) { return ls-Int(rs); }
    friend Int operator -(const int &ls, const Int &rs) { return Int(ls)-rs; }
    friend Int operator *(const Int &ls, const int &rs) { return ls*Int(rs); }
    friend Int operator *(const int &ls, const Int &rs) { return Int(ls)*rs; }
    bool operator <(const Int &rs) const { return x<rs.x; }
    bool operator ==(const Int &rs) const { return !(*this<rs or rs<*this); }
    bool operator !=(const Int &rs) const { return !(rs==*this); }
    bool operator >(const Int &rs) const { return (rs<*this); }
    bool operator <=(const Int &rs) const { return !(rs<*this); }
    bool operator >=(const Int &rs) const { return !(*this<rs); }
};

Int operator""_i(unsigned long long x) { return {int(x)}; }//}

int n, m, s, t;

struct Node {
    int at; ll cost;
    bool operator<(const Node &b) const { return cost>b.cost; }
};

struct Out { int v, w; };

list<Out> g[mxn];
priority_queue<Node> pq;
ll dist[mxn];
int prv[mxn];  // to print path later

void dijkstra(int src) {
    memset(dist, 63, sizeof(dist));
    dist[src] = 0, pq.push({src, 0}), prv[src] = -1;
    while (!pq.empty()) {
        Node u = pq.top(); pq.pop();
        if (u.cost!=dist[u.at]) continue;
        for (auto &i : g[u.at]) {
            ll os = u.cost+i.w;
            if (dist[i.v]>os) pq.push({i.v, dist[i.v] = os}), prv[i.v] = u.at;
        }
    }
}

list<int> dag[mxn];
void shortestPathDAG(int mnNode, int mxNode) {
    for (int i = mnNode; i <= mxNode; i++) {
        for (auto &j : g[i]) {
            if (dist[j.v]+j.w==dist[i]) dag[j.v].push_back(i);
        }
    }
}

Int dp/*shortest path from*/[mxn];
bitset<mxn> vstd;
void dfs(int u) {   // handle sources before starting.
    vstd[u] = 1;
    for (auto &v : dag[u]) {
        if (!vstd[v]) dfs(v);
        dp[u] += dp[v];//if(dp[v])cout << u << ' ' << v << '\n';
    }
}

list<int> dagReverse[mxn];
void reverseDag(int mnNode, int mxNode) {
    for (int i = mnNode; i <= mxNode; i++) {
        for (auto &j : dag[i]) {
            dagReverse[j].push_back(i);
        }
    }
}

Int dp2 /*shortest path to*/[mxn];
bitset<mxn> vstd2;
void dfs2(int u) {   // handle sinks before starting.
    vstd2[u] = 1;
    for (auto &v : dagReverse[u]) {
        if (!vstd2[v]) dfs2(v);
        dp2[u] += dp2[v];
    }
}


signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
/*If we find 2 different paths from s to t, it will be enough unless at mid point they are same.
Actually we only need count of shortest path through nodes which have dist[i]*2 == dist[t] and through edges that
dist[u]*2<dist[t] and dist[v]*2>dist[t]. Answer is total pair of shortest path count - pairs that go through those bad
nodes or edges. If number of shortest paths through x is sp, then number of ordered pair of shortest paths is x*(x-1).
Finding number of shortest path through a node or edge can be done:
Shortest path graph is a DAG, so we can do dp to find number of shortest path from each node and dp2 to find number of
shortest path to each node, shortest path through a node is sp[i] = dp[i]*dp2[i], through an edge u->v is dp2[u]*dp[v]*/

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w}), g[v].push_back({u, w});
    }

    dijkstra(s);
    shortestPathDAG(1, n);

    dp[t] = 1, dfs(s);
    reverseDag(1, n);
    dp2[s] = 1, dfs2(t);

    Int ans = dp[s]*(dp[s]-1);
    for (int i = 1; i <= n; i++) {
        if ((dist[i]<<1)!=dist[t]) continue;
        Int sp = dp[i]*dp2[i];
        ans -= sp*(sp-1);
    }
    for (int i = 1; i <= n; i++) {
        for (auto &j : dag[i]) {
            if (dist[i]<<1 >= dist[t] or dist[j]<<1 <= dist[t]) continue;
            Int sp = dp2[i]*dp[j];
            ans -= sp*(sp-1);
        }
    }
    cout << ans << '\n';
}