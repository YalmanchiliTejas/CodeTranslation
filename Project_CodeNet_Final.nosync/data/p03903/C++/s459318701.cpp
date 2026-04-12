#include <bits/stdc++.h>
using namespace std;
#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(...) debug_func_mult(split_names(#__VA_ARGS__), __VA_ARGS__)
#define DEBUG_ENDL endl << flush
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(...) 0
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

string to_string(const string &s) { return s; }

template <typename T, typename U>
string to_string(const P<T, U> &p) {
    string ret = "(";
    ret += to_string(p.first);
    ret += ", ";
    ret += to_string(p.second);
    ret += ")";
    return move(ret);
}

template <typename T>
string to_string(const V<T> &v) {
    string ret = "{";
    for(const T &t : v) {
        ret += to_string(t);
        ret += ", ";
    }
    ret += "}";
    return move(ret);
}

template <typename T>
void debug_func(const T &t, const string &s = "") {
    if(s.size()) cout << s << " = ";
    cout << to_string(t) << DEBUG_ENDL_S(s);
}

template <typename T>
void debug_func_mult(int idx, const V<string> &names, const T &t) {
    debug_func(t, names[idx]);
}

template <typename T>
void debug_func_mult(const V<string> &names, const T &t) {
    debug_func(t, names[0]);
}

template <typename Head, typename... Tail>
void debug_func_mult(int idx, const V<string> &names, const Head &head, const Tail&... args) {
    debug_func(head, names[idx]);
    debug_func_mult(idx + 1, names, args...);
}

template <typename Head, typename... Tail>
void debug_func_mult(const V<string> &names, const Head &head, const Tail&... args) {
    debug_func(head, names[0]);
    debug_func_mult(1, names, args...);
}

V<string> split_names(string &&s) {
    replace(ALL(s), ' ', ',');
    V<string> ret;
    istringstream ss(s);
    string t;
    while(getline(ss, t, ',')) if(t.size()) ret.push_back(move(t));
    return move(ret);
}

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

class UnionFind{
    using vec = vector<ll>;
    public:
        vec rank;
        vec parent;

        UnionFind(ll N){
            rank = vec(N, 0);
            parent = vec(N);
            iota(parent.begin(), parent.end(), 0ll);
        }

        ~UnionFind(){
        }

        ll find(ll child){
            return (child == parent[child] ? child : parent[child] = find(parent[child]));
        }

        void unit(ll x, ll y){
            ll px = find(x);
            ll py = find(y);
            if(px == py){
                return;
            }
            if(rank[px] < rank[py]){
                swap(px, py);
            }
            parent[py] = px;
            rank[px] += (rank[px] == rank[py]);
        }

        bool same(ll x, ll y){
            return (find(x) == find(y));
        }

};

using TLL = tuple<ll, ll, ll>;

int main() {
    init_io();
    ll N, M;
    cin >> N >> M;
    VV<PLL> edges(N);
    V<TLL> elis;
    for(ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
        elis.emplace_back(a, b, c);
    }

    ll cost = 0;
    V<TLL> used_edges;

    {
        UnionFind uf(N);
        sort(ALL(elis), [](TLL a, TLL b) { return get<2>(a) < get<2>(b); });
        for(const auto &tup : elis) {
            ll a, b, c;
            tie(a, b, c) = tup;
            if(uf.same(a, b)) continue;
            uf.unit(a, b);
            cost += c;
            used_edges.push_back(tup);
        }
    }

    ll Q;
    cin >> Q;
    V<PLL> st;
    for(ll i = 0; i < Q; i++) {
        ll s, t;
        cin >> s >> t;
        st.emplace_back(s - 1, t - 1);
    }
    V<ll> rcosts(Q, 0);

    {
        for(ll i = 0; i < N - 1; i++) {
            UnionFind uf(N);
            for(ll j = 0; j < N - 1; j++) {
                if(i == j) continue;
                ll a, b, c;
                tie(a, b, c) = used_edges[j];
                uf.unit(a, b);
            }

            ll unusedc = get<2>(used_edges[i]);

            for(ll j = 0; j < Q; j++) {
                ll s, t;
                tie(s, t) = st[j];
                if(uf.same(s, t)) continue;
                chmax(rcosts[j], unusedc);
            }
        }
    }

    for(ll e : rcosts) cout << cost - e << endl;
    return 0;
}
