#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

template <typename T, typename U>
class Dijkstra {
    private:
        struct Edge {
            T to;   // 有向辺の行先頂点
            U cost;  // 辺の重み
        };
        typedef pair<U, T> P;       // first: 最短距離 second: 頂点 id
    public:
        // コンストラクタ
        // v … 頂点数, inf: …「無限大」とする値
        Dijkstra(T v, U inf) : m_V(v), m_Inf(inf) {
            m_G.assign(m_V, vector<Edge>());
            m_Dist.assign(m_V, m_Inf);
            m_PrevP.assign(m_V, -1);
        }
        // 有向辺の追加。負のコストは未対応
        void AddDirEdge(T from, T to, U cost) { m_G[from].push_back({to, cost}); }
        // 無向辺の追加。負のコストは未対応
        void AddUndirEdge(T from, T to, U cost) {
            AddDirEdge(from, to, cost);
            AddDirEdge(to, from, cost);
        }
        // 始点 s から各頂点への最短経路の導出 O(E log V)
        // Calc を連続で行うことはできない。その場合は m_Dist と m_Prev の再初期化が必要
        void Calc(T s) {
            // 最短距離が短い順で cand を取り出す
            // 頂点 P.second まで P.first のコストで来れたことを情報として入れておく
            priority_queue<P, vector<P>, greater<P> > cand;
            m_Dist[s] = 0;  // 始点のコストは 0
            cand.push(P(0, s));
            while(!cand.empty()) {
                P p = cand.top(); cand.pop();     // cand のトップを取り出す
                T v = p.second;
                // 頂点 v まで最短経路が、 cand から取り出したものより既に小さいなら何もしない
                if(m_Dist[v] < p.first){ continue; }
                // 現在見ている頂点から延びている辺を全て見る
                for(Edge e : m_G[v]) {
                    if(m_Dist[e.to] > m_Dist[v] + e.cost) {
                        // 現在の最短経路より短くなるなら更新
                        m_Dist[e.to] = m_Dist[v] + e.cost;
                        m_PrevP[e.to] = v;
                        cand.push(P(m_Dist[e.to], e.to));
                    }
                }
            }
        }
        // 始点 s から頂点 t への最短距離を返す O(1)
        // 前処理として Calc(s) が必要
        U GetDist(T t) { return m_Dist[t]; }
        // 始点 s から頂点 t までの経路を vector に入れて返す (s と t 含む)
        // O(V') … V' は最短経路の頂点数
        // 前処理として Calc(s) が必要
        vector<T> GetPath(T t) {
            vector<T> path;
            for(; t != -1; t = m_PrevP[t]) { path.push_back(t); }  // t が s になるまで prev_p[t] を辿っていく
            // このままだと t->s の順になっているので逆順にする
            reverse(path.begin(), path.end());
            return path;
        }
    private:
        const T m_V;                // 頂点の数
        const U m_Inf;              // 無限の代わりとして扱う値
        vector< vector<Edge> > m_G; // 頂点 i から延びている辺の vector(隣接リスト)
        vector<U> m_Dist;           // 各頂点への最短コスト。つまり答え
        vector<T> m_PrevP;          // 最短経路の各頂点を保存(経路復元で利用)
};

ll N, M, S, T;
vector< tuple<ll, ll, ll> > edges;      // 辺集合
vector< pair<ll, ll> > graph[MAX_N];    // 隣接リスト。first: 行き先 second: コスト

ll dp_node_s[MAX_N], dp_node_t[MAX_N];

// 頂点 i を利用する最短経路のパターン数
// flag が　true なら S が始点、 false なら T が始点
ll dfs_node(Dijkstra<ll, ll>& dk, bool flag, ll i) {

    ll& ret = (flag) ? dp_node_s[i] : dp_node_t[i];
    if(flag && i == T) { ret = 1; }
    if(!flag && i == S) { ret = 1; }
    if(~ret) { return ret; }
    ret = 0;

    for(auto& n : graph[i]) {
        ll next_i = n.first;
        ll cost = n.second;
        // i -> から next_i が最短経路なら利用
        if(dk.GetDist(next_i) == dk.GetDist(i) + cost) {
            ret += dfs_node(dk, flag, next_i);
            ret %= MOD;
        }
    }

    return ret;
}

signed main()
{
    cin >> N >> M >> S >> T;
    S--; T--;

    Dijkstra<ll, ll> dk_s(N, LLINF), dk_t(N, LLINF);
    REP(i, M) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));
        dk_s.AddUndirEdge(u, v, d);
        dk_t.AddUndirEdge(u, v, d);
        edges.push_back(make_tuple(u, v, d));
    }

    dk_s.Calc(S);
    dk_t.Calc(T);

    MINUS(dp_node_s);
    MINUS(dp_node_t);
    dfs_node(dk_s, true, S);
    dfs_node(dk_t, false, T);

    ll ans = dp_node_s[S] * dp_node_s[S]; // 全パターン
    ans %= MOD;

    // 各頂点がかぶる可能性のある頂点かどうかチェック
    REP(n, N) {
        if(dk_s.GetDist(n) == dk_t.GetDist(n)) {
            // この頂点を経由するパターンはすべて使えない
            ll pat = dp_node_s[n] * dp_node_t[n];
            pat %= MOD;
            // このパターンどうしの組み合わせは使うことができない
            pat *= pat;
            pat %= MOD;

            ans = ans + MOD - pat;
            ans %= MOD;
        }
    }

    // 各辺がかぶる可能性のある辺かどうかチェック
    REP(i, M) {
        ll u = get<0>(edges[i]);
        ll v = get<1>(edges[i]);
        ll d = get<2>(edges[i]);

        // s に近い方を u にする
        if(dk_s.GetDist(v) < dk_s.GetDist(u)) { swap(u, v); }

        // この辺が最短経路で使われないなら、見る必要はない
        if(dk_s.GetDist(u) + d != dk_s.GetDist(v)) { continue; }

        // この辺の中でぶつかる可能性があるか
        ll dist_from_s = dk_s.GetDist(v);
        ll dist_from_t = dk_t.GetDist(u);
        if(dist_from_s <= dk_t.GetDist(v) ||
           dist_from_t <= dk_s.GetDist(u))
        {
            // ぶつからない
            continue;
        }

        // この辺を利用するパターンどうしの組み合わせは使うことができない
        ll pat = dp_node_t[u] * dp_node_s[v];
        pat %= MOD;
        pat *= pat;
        pat %= MOD;

        ans = ans + MOD - pat;
        ans %= MOD;
        //DBG("edge(%lld, %lld), pat: %lld\n", u, v, pat);
    }

    printf("%lld\n", ans);
    return 0;
}
