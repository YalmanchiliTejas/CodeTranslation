#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*
MinCostFlow: Minimum-cost flow problem solver WITH NO NEGATIVE CYCLE
Verified by SRM 770 Div1 Medium <https://community.topcoder.com/stat?c=problem_statement&pm=15702>
*/
struct MinCostFlow
{
    using TFLOW = int;
    using TCOST = int;
    const TCOST INF_COST = std::numeric_limits<TCOST>::max();
    struct edge {
        int to, rev;
        TFLOW cap;
        TCOST cost;
        friend std::ostream &operator<<(std::ostream &os, const edge &e) {
            os << '(' << e.to << ',' << e.rev << ',' << e.cap << ',' << e.cost << ')';
            return os;
        }
    };
    int V;
    std::vector<std::vector<edge>> G;
    std::vector<TCOST> dist;
    std::vector<int> prevv, preve;
    std::vector<TCOST> h;  // h[V]: potential

    bool _calc_distance_bellman_ford(int s) {  // O(VE), able to detect negative cycle
        dist.assign(V, INF_COST);
        dist[s] = 0;
        bool upd = true;
        int cnt = 0;
        while (upd) {
            upd = false;
            cnt++;
            if (cnt > V) return false;  // Negative cycle existence
            for (int v = 0; v < V; v++) if (dist[v] != INF_COST) {
                for (int i = 0; i < (int)G[v].size(); i++) {
                    edge &e = G[v][i];
                    TCOST c = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 and dist[e.to] > c) {
                        dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
                        upd = true;
                    }
                }
            }
        }
        return true;
    }

    bool _calc_distance_dijkstra(int s) {  // O(ElogV)
        dist.assign(V, INF_COST);
        dist[s] = 0;
        using P = std::pair<TCOST, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> q;
        q.emplace(0, s);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                TCOST c = dist[v] + e.cost + h[v] - h[e.to];
                if (e.cap > 0 and dist[e.to] > c) {
                    dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
                    q.emplace(dist[e.to], e.to);
                }
            }
        }
        return true;
    }

    MinCostFlow(int V=0) : V(V), G(V) {}

    void add_edge(int from, int to, TFLOW cap, TCOST cost) {
        G[from].emplace_back(edge{to, (int)G[to].size(), cap, cost});
        G[to].emplace_back(edge{from, (int)G[from].size() - 1, (TFLOW)0, -cost});
    }

    std::pair<TCOST, std::pair<bool, TFLOW>> flush(int s, int t, TFLOW f) {
        /*
        Flush amount of `f` from `s` to `t` using the Dijkstra's algorithm
        works for graph with no negative cycles (negative cost edges are allowed)
        retval: (min_flow, ([succeeded or not], residue flow))
        [Example] Succeeded: `([mincost], (true, 0))`
        */
        TCOST ret = 0;
        h.assign(V, 0);
        prevv.assign(V, -1);
        preve.assign(V, -1);
        while (f > 0) {
            _calc_distance_dijkstra(s);
            if (dist[t] == INF_COST) return std::make_pair(ret, std::make_pair(false, f));
            for (int v = 0; v < V; v++) h[v] += dist[v];
            TFLOW d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = std::min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            ret += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return std::make_pair(ret, std::make_pair(true, 0));
    }

    friend std::ostream &operator<<(std::ostream &os, const MinCostFlow &mcf) {
        os << "[MinCostFlow]V=" << mcf.V << ":";
        for (int i = 0; i < (int)mcf.G.size(); i++) for (auto &e : mcf.G[i]) {
            os << "\n" << i << "->" << e.to << ": cap=" << e.cap << ", cost=" << e.cost;
        }
        return os;
    }
};

// MaxFlow (Dinic algorithm)
template <typename T>
struct MaxFlow
{
    struct edge { int to; T cap; int rev; };
    std::vector<std::vector<edge>> edges;
    std::vector<int> level;  // level[i] = distance between vertex S and i (Default: -1)
    std::vector<int> iter;  // iteration counter, used for Dinic's DFS
    std::vector<int> used;  // Used for Ford-Fulkerson's Algorithm

    void bfs(int s)
    {
        level.assign(edges.size(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (edge &e : edges[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs_dinic(int v, int goal, T f)
    {
        if (v == goal) return f;
        for (int &i = iter[v]; i < (int)edges[v].size(); i++) {
            edge &e = edges[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs_dinic(e.to, goal, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T dfs_ff(int v, int goal, T f)
    {
        if (v == goal) return f;
        used[v] = true;
        for (edge &e : edges[v]) {
            if (e.cap > 0 && !used[e.to]) {
                T d = dfs_ff(e.to, goal, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    MaxFlow(int N) { edges.resize(N); }
    void add_edge(int from, int to, T capacity)
    {
        edges[from].push_back(edge{to, capacity, (int)edges[to].size()});
        edges[to].push_back(edge{from, (T)0, (int)edges[from].size() - 1});
    }

    // Dinic algorithm
    // Complexity: O(VE)
    T Dinic(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            iter.assign(edges.size(), 0);
            T f;
            while ((f = dfs_dinic(s, t, INF)) > 0) flow += f;
        }
    }

    // Ford-Fulkerson algorithm
    // Complexity: O(EF)
    T FF(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            used.assign(edges.size(), 0);
            T f = dfs_ff(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }

    void back_flow(int s, int t, int s_e, int t_e, T capacity_reduce)
    {
        int i;
        for (i=0; edges[s_e][i].to != t_e; ) i++;
        edge &e = edges[s_e][i];

        if (capacity_reduce <= e.cap) {
            e.cap -= capacity_reduce;
        }
        else {
            T flow = capacity_reduce - e.cap;
            e.cap = 0;
            edges[e.to][e.rev].cap -= flow;

            T f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(t, t_e, flow - f_sum);
            }
            f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(s_e, s, flow - f_sum);
            }
        }
    }
};

void No()
{
    puts("-1");
    exit(0);
}

int main()
{
    int N;
    cin >> N;
    using ull = unsigned long long;

    vector<int> S(N), T(N);
    vector<ull> U(N), V(N);
    cin >> S >> T >> U >> V;

    vector<vector<ull>> ret(N, vector<ull>(N));
    REP(d, 64)
    {
        MaxFlow<int> mf(N * 2 + 4);
        int s = N * 2, t = N * 2 + 1, SS = N * 2 + 2, TT = N * 2 + 3;
        REP(i, N) REP(j, N) mf.add_edge(i, N + j, 1);

        mf.add_edge(SS, s, 1e8);
        mf.add_edge(t, TT, 1e8);

        REP(i, N)
        {
            if (S[i])
            {
                if ((U[i] >> d) & 1)
                {
                    mf.add_edge(s, i, N - 1);
                    mf.add_edge(SS, i, 1);
                    mf.add_edge(s, TT, 1);
                }
            }
            else
            {
                if ((U[i] >> d) & 1)
                {
                    mf.add_edge(SS, i, N);
                    mf.add_edge(s, TT, N);
                }
                else
                {
                    mf.add_edge(s, i, N - 1);
                }
            }
        }
        REP(j, N)
        {
            if (T[j])
            {
                if ((V[j] >> d) & 1)
                {
                    mf.add_edge(j + N, t, N - 1);
                    mf.add_edge(SS, t, 1);
                    mf.add_edge(j + N, TT, 1);
                }
            }
            else
            {
                if ((V[j] >> d) & 1)
                {
                    mf.add_edge(SS, t, N);
                    mf.add_edge(j + N, TT, N);
                }
                else
                {
                    mf.add_edge(j + N, t, N - 1);
                }
            }
        }
        mf.Dinic(SS, TT);
        mf.Dinic(s, TT);
        mf.Dinic(SS, t);
        mf.Dinic(s, t);
        // mcf.flush(s, t, N * N);
        REP(i, N)
        {
            // for (auto e : mcf.G[i]) if (e.to >= N and e.to < N * 2 and e.cap == 0)
            for (auto e : mf.edges[i]) if (e.to >= N and e.to < N * 2 and e.cap == 0)
            {
                ret[i][e.to - N] += 1ULL << d;
            }
        }
    }

    REP(i, N)
    {
        ull s;
        if (S[i])
        {
            s = 0;
            REP(j, N) s |= ret[i][j];
        }
        else
        {
            s = -1;
            REP(j, N) s &= ret[i][j];
        }
        if (s != U[i]) No();
    }
    REP(j, N)
    {
        ull s;
        if (T[j])
        {
            s = 0;
            REP(i, N) s |= ret[i][j];
        }
        else
        {
            s = -1;
            REP(i, N) s &= ret[i][j];
        }
        if (s != V[j]) No();
    }
    REP(i, N)
    {
        REP(j, N) cout << ret[i][j] << ' ';
        cout << '\n';
    }
}
