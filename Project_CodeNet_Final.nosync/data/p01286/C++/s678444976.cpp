#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
template <class T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr int INF = 1e9;

struct Dinic {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    Dinic(int V) : V(V) { G.assign(V, vector<edge>()); }
    
    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge){to, cap, (int)(G[to].size())});
        G[to].push_back((edge){from, 0, (int)(G[from].size() - 1)});
    }

    void bfs(int s) {
        level.assign(V, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = itr[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};

signed main() {
    while (1) {
        int H, W, C, M, NW, NC, NM;
        cin >> H >> W >> C >> M >> NW >> NC >> NM;
        if (H < 0) break;

        Dinic flow(2 + (H + W + C + M) * 2 + 6);
        const int S = 0, T = 1;
        auto hero = [&](int i) { return i + 2; };
        auto worrior = [&](int i) { return 2 + H * 2 + i; };
        auto cleric = [&](int i) { return 2 + (H + W) * 2 + 2 + i; };
        auto mage = [&](int i ) { return 2 + (H + W + C) * 2 + 4 + i; };
        int nw1 = worrior(W * 2);
        int nw2 = worrior(W * 2 + 1);
        int nc1 = cleric(C * 2);
        int nc2 = cleric(C * 2 + 1);
        int nm1 = mage(M * 2);
        int nm2 = mage(M * 2 + 1);

        rep(i, 0, W) {
            int n;
            cin >> n;
            rep(j, 0, n) {
                int hi;
                cin >> hi;
                hi--;
                flow.add_edge(hero(hi * 2 + 1), worrior(i * 2), 1);
            }
        }
        rep(i, 0, C) {
            int n;
            cin >> n;
            rep(j, 0, n) {
                int wi;
                cin >> wi;
                wi--;
                flow.add_edge(worrior(wi * 2 + 1), cleric(i * 2), 1);
            }
        }
        rep(i, 0, M) {
            int n;
            cin >> n;
            rep(j, 0, n) {
                int ci;
                cin >> ci;
                ci--;
                flow.add_edge(cleric(ci * 2 + 1), mage(i * 2), 1);
            }
        }

        // nw1 -> nw2
        flow.add_edge(nw1, nw2, NW);
        // nc1 -> nc2
        flow.add_edge(nc1, nc2, NC);
        // nm1 -> nm2
        flow.add_edge(nm1, nm2, NM);
        
        // S -> each Hero
        rep(i, 0, H) flow.add_edge(S, hero(i * 2), 1);
        // each mage -> T
        rep(i, 0, M) flow.add_edge(mage(i * 2 + 1), T, 1);
        flow.add_edge(nm2, T, INF);

        // each Hero -> nw1
        rep(i, 0, H) flow.add_edge(hero(i * 2 + 1), nw1, 1);
        // nw2 -> each cleric
        rep(i, 0, C) flow.add_edge(nw2, cleric(i * 2), 1);
        // each worrior -> nc1
        rep(i, 0, W) flow.add_edge(worrior(i * 2 + 1), nc1, 1);
        // nc2 -> each mage
        rep(i, 0, M) flow.add_edge(nc2, mage(i * 2), 1);
        // each cleric -> nm1
        rep(i, 0, C) flow.add_edge(cleric(i * 2 + 1), nm1, 1);

        rep(i, 0, H) flow.add_edge(hero(i * 2), hero(i * 2 + 1), 1);
        rep(i, 0, W) flow.add_edge(worrior(i * 2), worrior(i * 2 + 1), 1);
        rep(i, 0, C) flow.add_edge(cleric(i * 2), cleric(i * 2 + 1), 1);
        rep(i, 0, M) flow.add_edge(mage(i * 2), mage(i * 2 + 1), 1);

        int ans = flow.max_flow(S, T);
        cout << ans << endl;
    }
}
