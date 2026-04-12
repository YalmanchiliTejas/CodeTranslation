#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define TOUPPER(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define TOLOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define FILLZERO(s, n)                      \
    do {                                    \
        ostringstream os;                   \
        os << setw(n) << setfill('0') << s; \
        s = os.str();                       \
    } while (0);
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
#define INIT                               \
    std::cin.tie(nullptr);                 \
    std::ios_base::sync_with_stdio(false); \
    cout << std::fixed << std::setprecision(10);

constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

//0-indexedに注意
class Graph {
    struct edge {
        int from, to, cost;
        edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    };

public:
    int verN;
    int edgeN = 0;
    vector<edge> edge_set;
    vector<vector<pair<int, int>>> adj_list;
    int inf = numeric_limits<int>::max();
    Graph(int verN) : verN(verN), adj_list(verN) {}

    void add_directed_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        adj_list[from].push_back(make_pair(to, cost));
        edgeN++;
    }

    void add_undirected_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        edge_set.push_back(edge(to, from, cost));
        adj_list[from].push_back(make_pair(to, cost));
        adj_list[to].push_back(make_pair(from, cost));
        edgeN += 2;
    }

    bool _cycleDetection(int now, int prev, vector<int> &seen, vector<int> &used, vector<int> &cycle) {
        if (used[now]) {
            return false;
        }
        if (seen[now]) {
            cycle.push_back(now);
            return true;
        }

        seen[now] = true;

        for (auto adj_pair : adj_list[now]) {
            int adj = adj_pair.first;
            if (prev == adj)
                continue;
            bool hasDetected = _cycleDetection(adj, now, seen, used, cycle);
            if (hasDetected) {
                cycle.push_back(now);
                return true;
            }
        }
        used[now] = true;

        seen[now] = false;

        return false;
    }

    bool cycleDetection(vector<int> &cycle) {
        cycle.reserve(N);
        vector<int> seen(N);
        vector<int> used(N);
        for (int start = 0; start < N; start++) {
            bool hasDetected = _cycleDetection(start, -1, seen, used, cycle);
            if (hasDetected) {
                for (int i = 1; i < (int)cycle.size(); i++) {
                    if (cycle[i] == cycle[0]) {
                        cycle.erase(cycle.begin() + i + 1, cycle.end());
                    }
                }
                reverse(cycle.begin(), cycle.end());
                //cycle.pop_back();
                return 1;
            }
        }
        return 0;
    }

    int prim(int start, vector<int> &parent) {
        parent.resize(N);
        int cost = 0;
        vector<pair<int, int>> edgeSet;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> used(verN, 0);
        pq.push(make_pair(0, make_pair(start, start)));
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            int now = tmp.second.first;
            if (used[now])
                continue;
            cost += tmp.first;
            parent[now] = tmp.second.second;
            used[now] = 1;
            for (auto adj_pair : adj_list[now]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                if (used[adj])
                    continue;
                pq.push(make_pair(dist, make_pair(adj, now)));
            }
        }
        return cost;
    }

    //始点から行けるすべての負閉路を検出する。
    //始点関係なくあらゆる負閉路を検出したい場合、dをすべて0で初期化する。
    bool bellmanford(int start, vector<int> &d) {
        d.resize(verN);
        for (int i = 0; i < verN; i++) {
            d[i] = inf;
        }
        d[start] = 0;
        for (int i = 0; i < verN; i++) {
            for (int j = 0; j < edgeN; j++) {
                edge e = edge_set[j];
                if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i == verN - 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    //始点から終点へのパス上の不閉路を検出する。
    bool bellmanford(int start, int end, vector<int> &d) {
        d.resize(verN);
        vector<int> negative(verN);
        for (int i = 0; i < verN; i++) {
            d[i] = inf;
        }
        d[start] = 0;
        for (int i = 0; i < verN; i++) {
            for (int j = 0; j < edgeN; j++) {
                edge e = edge_set[j];
                if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i == verN - 1) {
                        negative[e.to] = true;
                    }
                }
            }
        }
        for (int i = 0; i < verN; i++) {
            for (int j = 0; j < edgeN; j++) {
                edge e = edge_set[j];
                if (negative[e.from]) {
                    negative[e.to] = true;
                }
            }
        }
        return !negative[end];
    }

    vector<int> dijkstra(int start) {
        vector<int> d(verN, inf);
        d[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> used(verN, 0);
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            int now = pq.top().second;
            pq.pop();
            if (used[now])
                continue;
            used[now] = 1;
            for (auto adj_pair : adj_list[now]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                if (used[adj])
                    continue;
                if (d[adj] > d[now] + dist) {
                    d[adj] = d[now] + dist;
                    pq.push(make_pair(d[adj], adj));
                }
            }
        }
        return d;
    }

    vector<vector<int>> warshallfloyd() {
        vector<vector<int>> d(verN, vector<int>(verN, inf));
        for (int i = 0; i < verN; i++) {
            for (auto adj_pair : adj_list[i]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                d[i][adj] = dist;
            }
        }
        for (int i = 0; i < verN; i++) {
            d[i][i] = 0;
        }
        for (int k = 0; k < verN; k++) {         // 経由する頂点
            for (int i = 0; i < verN; i++) {     // 始点
                for (int j = 0; j < verN; j++) { // 終点
                    if (d[i][k] != inf && d[k][j] != inf)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        return d;
    }
};

signed main() {
    INIT;
    cin >> N >> M;
    map<pi, int> mp;
    REP(i, M) {
        cin >> A >> B;
        A--, B--;
        mp[{A, B}] = 1;
        mp[{B, A}] = 1;
    }
    vi v(N);
    iota(ALL(v), 0);
    do {
        dump(v);
        int cnt = 0;
        REP(i, N - 1) {
            if (mp[{v[i], v[i + 1]}]) {
                cnt++;
            }
        }
        if (cnt == N - 1)
            ans++;
    } while (next_permutation(v.begin() + 1, v.end()));
    cout << ans << endl;
}