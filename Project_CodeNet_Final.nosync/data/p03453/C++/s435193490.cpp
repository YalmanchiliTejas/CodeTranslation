#include <bits/stdc++.h>
using namespace std;
//#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(X) debug_func(X, #X)
#define DEBUG_ENDL endl << flush
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(X) 0
#define DEBUG_ENDL 0
#define DEBUG_SEPARATOR_LINE 0
#endif
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define DEBUG_ENDL_S(S) ((S).size() ? "\n" : "") << flush;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
void debug_func_preffix(const string &s) { if(s.size()) cout << s << " = "; }
template <typename T>
void debug_func(const T &t, const string &s = "") {
    debug_func_preffix(s);
    cout << t << DEBUG_ENDL_S(s);
}
template <typename T, typename U>
void debug_func(const P<T, U> &p, const string &s = "") {
    debug_func_preffix(s);
    cout << "(";
    debug_func(p.first);
    cout << ", ";
    debug_func(p.second);
    cout << ")" << DEBUG_ENDL_S(s);
}
template <typename T>
void debug_func(const V<T> &v, const string &s = "") {
    for(ll i = 0; i < v.size(); i++) {
        string t = s + "[" + to_string(i) + "]";
        debug_func(v[i], t);
    }
}

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

template<typename T>
class Dijk {
private:
    template <typename U> using Edge = pair<ll, U>;
    template <typename U> using Edges = vector<Edge<U>>;
    template <typename U> using PQ = priority_queue<pair<ll, U>, vector<pair<ll, U>>, function<bool(pair<ll, U>, pair<ll, U>)>>;
    
    const vector<Edges<T>> &edges;
    T inf;
    T identity_ele;
        
public:
    Dijk(const vector<Edges<T>> &edges, T inf, T identity_ele)
        : edges(edges),
          inf(inf),
          identity_ele(identity_ele) {}

    vector<T> dijk(ll start) {
        vector<T> d(edges.size(), inf);
        d[start] = identity_ele;
        PQ<T> q([&](const Edge<T> &a, const Edge<T> &b) {return a.second > b.second;});
        q.push(make_pair(start, identity_ele));
        while(q.size()) {
            ll now;
            T dis;
            tie(now, dis) = q.top();
            q.pop();
            if(d[now] < dis) {
                continue;
            }
            for(const auto &e : edges[now]) {
                ll nxt;
                T cost;
                tie(nxt, cost) = e;
                if(d[nxt] == inf || dis + cost < d[nxt]) {
                    d[nxt] = dis + cost;
                    q.push(make_pair(nxt, dis + cost));
                }
            }
        }
        return d;
    }
};

ll N;
const ll MOD = 1e9 + 7;

V<ll> calc_perm(const V<ll> &nodes, const V<ll> &dists, const VV<PLL> &edges, ll start, ll goal) {
    V<ll> ret(N, 0);
    ret[nodes[0]] = 1;
    for(ll now : nodes) {
        if(now == goal) break;
        for(PLL e : edges[now]) {
            ll nxt, d;
            tie(nxt, d) = e;
            if(dists[nxt] != dists[now] + d) continue;
            if(nxt != goal && dists[nxt] >= dists[goal]) continue;
            (ret[nxt] += ret[now]) %= MOD;
        }
    }
    return move(ret);
}

ll calc_remove_collision(const VV<PLL> &edges, const V<tuple<ll, ll, ll>> &edget, const V<ll> &cdist, const V<ll> &adist, ll S, ll T) {
    V<ll> nodes(N);
    iota(ALL(nodes), 0ll);
    sort(ALL(nodes), [&](ll a, ll b) { return cdist[a] < cdist[b]; });
    auto from_start = calc_perm(nodes, cdist, edges, S, T);
    sort(ALL(nodes), [&](ll a, ll b) { return adist[a] < adist[b]; });
    auto from_goal = calc_perm(nodes, adist, edges, T, S);

    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        if(2 * cdist[i] == cdist[T] && 
           2 * adist[i] == cdist[T]) {
            ll tmp = from_start[i] * from_goal[i] % MOD;
            tmp *= tmp;
            tmp %= MOD;
            sum += tmp;
            sum %= MOD;
        }
    }

    DEBUG(cdist);
    DEBUG(adist);
    DEBUG(from_start);
    DEBUG(from_goal);

    for(const auto &e : edget) {
        ll a, b, d;
        tie(a, b, d) = e;
        if(cdist[a] > cdist[b]) swap(a, b);
        if(cdist[a] + d != cdist[b]) continue;
        if(cdist[a] + d + adist[b] != cdist[T]) continue;
        if(!(2 * cdist[a] < cdist[T] && cdist[T] < 2 * cdist[b])) continue;
        //if(!(2 * adist[b] < cdist[T] && cdist[T] < 2 * adist[a])) continue;
        DEBUG(make_pair(a, b));
        ll p = from_start[a] * from_goal[b] % MOD;
        p = p * p % MOD;
        (sum += p) %= MOD;
    }
    ll allp = from_start[T];
    allp = allp * allp % MOD;
    sum = MOD - sum;
    (allp += sum) %= MOD;
    return allp;
}

const ll INF = LLONG_MAX / 2 - 2e9;

int main() {
    ll M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    VV<PLL> edges(N);
    V<tuple<ll, ll, ll>> edget;
    for(ll i = 0; i < M; i++) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
        edget.emplace_back(u, v, d);
    }
    auto cdist = move(Dijk<ll>(edges, INF, 0).dijk(S));
    auto adist = move(Dijk<ll>(edges, INF, 0).dijk(T));
    cout << calc_remove_collision(edges, edget, cdist, adist, S, T) << endl;
    return 0;
}
