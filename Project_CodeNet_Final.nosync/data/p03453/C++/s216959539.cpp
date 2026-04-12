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
        Dijkstra() {}
        Dijkstra(T v, U inf) { Init(v, inf); }
        void Init(T v, U inf) {
            m_V = v;
            m_Inf = inf;
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
        T m_V;                // 頂点の数
        U m_Inf;              // 無限の代わりとして扱う値
        vector< vector<Edge> > m_G; // 頂点 i から延びている辺の vector(隣接リスト)
        vector<U> m_Dist;           // 各頂点への最短コスト。つまり答え
        vector<T> m_PrevP;          // 最短経路の各頂点を保存(経路復元で利用)
};

// 2 点間の最短経路ユーティリティ
// 始点 s と終点 t が分かっている場合に利用できる
// 有向辺未対応
//
// 以下がわかる
// - 単一始点最短距離(Dijkstra)
// - 最短経路のパターン数
// - 頂点 n を利用する (s, t) 間最短経路のパターン数
// - 辺(u, v) を利用する (s, t) 間最短経路のパターン数
//
// 頂点 id は [0, m_N) であると想定して動く
class STFastPath {
    public:
        STFastPath() {}
        // n : 頂点数
        STFastPath(ll n, ll mod) { Init(n, mod); }
        void Init(ll n, ll mod) {
            m_N = n;
            m_Mod = mod;
            m_DkS.Init(m_N, LLINF);
            m_DkT.Init(m_N, LLINF);
            m_Graph.assign(m_N, vector< pair<ll, ll> >());
            m_DpNodeS.assign(m_N, -1);
            m_DpNodeT.assign(m_N, -1);
        }

        void AddUndirEdge(ll u, ll v, ll d) {
            m_Graph[u].push_back(make_pair(v, d));
            m_Graph[v].push_back(make_pair(u, d));
            m_DkS.AddUndirEdge(u, v, d);
            m_DkT.AddUndirEdge(u, v, d);
        }

        void Build(ll s, ll t) {
            m_S = s;
            m_T = t;
            m_DkS.Calc(m_S);
            m_DkT.Calc(m_T);
            Dfs(true, t);
            Dfs(false, s);
        }

        // --- 以降 Build() 後のみ取得可能

        // 最短経路の全パターン数
        ll GetAllPattern() { return GetNodeThroughPattern(m_S); }

        // ノード n を経由する最短経路のパターン数
        ll GetNodeThroughPattern(ll n) {
            ll ret = m_DpNodeS[n] * m_DpNodeT[n];
            ret %= MOD;
            return ret;
        }

        // 辺 (u, v) を経由する最短経路のパターン数
        // ※辺 (u, v) の存在確認はしないので注意
        ll GetEdgeThroughPattern(ll u, ll v) {
            ll ret = m_DpNodeS[u] * m_DpNodeT[v];
            ret %= MOD;
            return ret;
        }

        // 頂点 n が最短経路で利用されるなら true を返す
        bool IsNodeUsed(ll n) {
            return (m_DkS.GetDist(m_T) == m_DkS.GetDist(n) + m_DkT.GetDist(n));
        }

        // 辺 ({u, v}, d) が最短経路で利用されるなら true を返す
        // d はコスト
        // ※辺 (u, v) の存在確認はしないので注意
        bool IsEdgeUsed(ll u, ll v, ll d) {
            // s に近い方を u にする
            if(m_DkS.GetDist(v) < m_DkS.GetDist(u)) { swap(u, v); }
            return (m_DkS.GetDist(u) + d == m_DkS.GetDist(v));
        }

        // 始点 m_S の n までの最短距離
        ll GetDistS(ll n) { return m_DkS.GetDist(n); }
        // 始点 m_T の n までの最短距離
        ll GetDistT(ll n) { return m_DkT.GetDist(n); }

    private:
        // 頂点 S/T から頂点 i までの最短経路のパターン数
        // flag が　true なら S が始点、 false なら T が始点
        ll Dfs(bool flag, ll i) {

            ll& ret = (flag) ? m_DpNodeS[i] : m_DpNodeT[i];
            if(flag && i == m_S) { ret = 1; }
            if(!flag && i == m_T) { ret = 1; }
            if(~ret) { return ret; }
            ret = 0;

            for(auto& n : m_Graph[i]) {
                ll next_i = n.first;
                ll cost = n.second;
                // i -> next_i が最短経路なら利用
                ll dist_i = m_DkS.GetDist(i);
                ll dist_next_i = m_DkS.GetDist(next_i);
                if(flag) {
                    dist_i = m_DkT.GetDist(i);
                    dist_next_i = m_DkT.GetDist(next_i);
                }
                if(dist_next_i == dist_i + cost) {
                    ret += Dfs(flag, next_i);
                    ret %= MOD;
                }
            }

            return ret;
        }

    private:
        ll m_N;                                 // 頂点数
        ll m_S, m_T;                            // 始点と終点
        ll m_Mod;                               // 剰余
        Dijkstra<ll, ll> m_DkS;                  // s を始点としたダイクストラ
        Dijkstra<ll, ll> m_DkT;                  // T を始点としたダイクストラ
        vector< vector< pair<ll, ll> > > m_Graph;   // 隣接リスト first: 行き先 second: コスト
        vector<ll> m_DpNodeS;                   // 頂点 S から頂点 i までの最短経路のパターン数
        vector<ll> m_DpNodeT;                   // 頂点 T から頂点 i までの最短経路のパターン数
};


ll N, M, S, T;
vector< tuple<ll, ll, ll> > edges;      // 辺集合

signed main()
{
    cin >> N >> M >> S >> T;
    S--; T--;

    STFastPath fp(N, MOD);
    REP(i, M) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        edges.push_back(make_tuple(u, v, d));
        fp.AddUndirEdge(u, v, d);
    }

    fp.Build(S, T);

    ll ans = fp.GetAllPattern(); // 全パターン
    ans *= ans;
    ans %= MOD;

    // 各頂点がかぶる可能性のある頂点かどうかチェック
    REP(n, N) {
        if(!fp.IsNodeUsed(n)) { continue; }
        if(fp.GetDistS(n) == fp.GetDistT(n)) {
            // この頂点を経由するパターンはすべて使えない
            ll pat = fp.GetNodeThroughPattern(n);
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

        if(!fp.IsEdgeUsed(u, v, d)) { continue; }

        // s に近い方を u にする
        if(fp.GetDistS(v) < fp.GetDistS(u)) { swap(u, v); }

        // この辺の中でぶつかる可能性があるか
        ll dist_from_s = fp.GetDistS(v);
        ll dist_from_t = fp.GetDistT(u);
        if(dist_from_s <= fp.GetDistT(v) ||
           dist_from_t <= fp.GetDistS(u))
        {
            // ぶつからない
            continue;
        }

        // この辺を利用するパターンどうしの組み合わせは使うことができない
        ll pat = fp.GetEdgeThroughPattern(u, v);
        pat *= pat;
        pat %= MOD;

        ans = ans + MOD - pat;
        ans %= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
