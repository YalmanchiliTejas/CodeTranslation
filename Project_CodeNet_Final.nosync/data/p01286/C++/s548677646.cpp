#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

template<class T>
struct dinic {
    struct edge{
        int to;
        T cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> G;
    vector<int> level, iter;

    void bfs(int s) {
        level.assign(G.size(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(que.size()) {
            int v = que.front(); que.pop();
            for(auto i: G[v]) {
                if(i.cap > 0 && level[i.to] < 0) {
                    level[i.to] = level[v] + 1;
                    que.push(i.to);
                }
            }
        }
    }

    T dfs(int v, const int t, T f) {
        if(v == t) return f;
        for(int &i = iter[v]; i<(ll)G[v].size(); ++i) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    dinic() {}
    dinic(int n) : G(n), level(n), iter(n) {}

    void add_edge(int from, int to, T cap) {
        G[from].push_back({to, cap, (int)G[to].size(), false});
        G[to].push_back({from, 0, (int)G[from].size()-1, true});
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while(1) {
            bfs(s);
            if(level[t] < 0) return flow;
            iter.assign(G.size(), 0);
            T f;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }

    friend ostream &operator <<(ostream& out, const dinic& a){
        out << endl;
        for(int i = 0; i < (int)a.G.size(); i++) {
            for(auto &e : a.G[i]) {
                if(e.isrev) continue;
                auto &rev_e = a.G[e.to][e.rev];
                out << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
        return out;
    }
};

int main(void) {
    while(1) {
        ll h, w, c, m, nw, nc, nm;
        cin >> h >> w >> c >> m >> nw >> nc >> nm;
        if(h == -1) break;

        dinic<ll> flow(h + (w+1)*2 + (c+1)*2 + (m+1)*2 + 2);
        ll s = h + (w+1)*2 + (c+1)*2 + (m+1)*2, t = s+1;

        // type=0 勇者
        // type=1 戦士
        // type=2 僧侶
        // type=3 魔法使い
        auto trans = [&](ll type, ll num, bool is_in) {
            if(type == 0) {
                return num; 
            } else if(type == 1) {
                if(is_in) return h + 2*num;
                else return h + 2*num + 1; 
            } else if(type == 2) {
                if(is_in) return h + (w+1)*2 + 2*num;
                else return h + (w+1)*2 + 2*num + 1;
            } else if(type == 3) {
                if(is_in) return h + (w+1)*2 + (c+1)*2 + 2*num;
                else return h + (w+1)*2 + (c+1)*2 + 2*num + 1;
            }
            assert(false);
        };

        // 始点 → 勇者
        REP(i, h) flow.add_edge(s, trans(0, i, true), 1);

        // 勇者 → 戦士
        REP(i, w) {
            ll n;
            cin >> n;
            REP(j, n) {
                ll x;
                cin >> x;
                x--;
                // 勇者x → 戦士i
                flow.add_edge(trans(0, x, false), trans(1, i, true), 1);
            }
        }
        REP(i, h) flow.add_edge(trans(0, i, false), trans(1, w, true), 1);
        REP(i, w) flow.add_edge(trans(1, i, true), trans(1, i, false), 1);
        flow.add_edge(trans(1, w, true), trans(1, w, false), nw);

        // 戦士 → 僧侶
        REP(i, c) {
            ll n;
            cin >> n;
            REP(j, n) {
                ll x;
                cin >> x;
                x--;
                // 戦士x → 僧侶i
                flow.add_edge(trans(1, x, false), trans(2, i, true), 1);
            }
        }
        REP(i, w) flow.add_edge(trans(1, i, false), trans(2, c, true), 1);
        REP(i, c) flow.add_edge(trans(1, w, false), trans(2, i, true), 1);
        REP(i, c) flow.add_edge(trans(2, i, true), trans(2, i, false), 1);
        flow.add_edge(trans(2, c, true), trans(2, c, false), nc);

        // 僧侶 → 魔法使い
        REP(i, m) {
            ll n;
            cin >> n;
            REP(j, n) {
                ll x;
                cin >> x;
                x--;
                // 僧侶x → 魔法使いi
                flow.add_edge(trans(2, x, false), trans(3, i, true), 1);
            }
        }
        REP(i, c) flow.add_edge(trans(2, i, false), trans(3, m, true), 1);
        REP(i, m) flow.add_edge(trans(2, c, false), trans(3, i, true), 1);
        REP(i, m) flow.add_edge(trans(3, i, true), trans(3, i, false), 1);
        flow.add_edge(trans(3, m, true), trans(3, m, false), nm);

        // 魔法使い → 終点
        REP(i, m) flow.add_edge(trans(3, i, false), t, 1);
        flow.add_edge(trans(3, m, false), t, nm);

        cout << flow.max_flow(s, t) << endl;
        dump(flow);
    }

    return 0;
}
