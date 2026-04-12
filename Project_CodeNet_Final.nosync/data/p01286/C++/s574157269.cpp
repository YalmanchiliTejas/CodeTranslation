#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, cap, rev;
};

using edges = vector<edge>;
using graph = vector<edges>;

void add_edge(graph& g, int from, int to, int cap) {
    g[from].push_back(edge{to, cap, (int)g[to].size()});
    g[to].push_back(edge{from, 0, (int)g[from].size()-1});
}

int dfs(graph& g, vector<bool>& used, int v, int t, int f) {
    if(v == t) {
        return f;
    }
    used[v] = true;
    for(int i=0; i<g[v].size(); ++i) {
        edge& e = g[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(g, used, e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(graph& g, int s, int t) {
    int flow = 0;
    int INF = 1e9;
    vector<bool> used(g.size());
    while(true) {
        fill(used.begin(), used.end(), false);
        int f = dfs(g, used, s, t, INF);
        if(f == 0) {
            return flow;
        }
        flow += f;
    }
}

int main() {
    int H, W, C, M, Nw, Nc, Nm;
    while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm, H != -1) {
        const int V = H + 2*(W + 1) + 2*(C + 1) + (M + 1) + 1 + 1;
        const int w0 = H;
        const int w1 = w0 + (W + 1);
        const int c0 = w1 + (W + 1);
        const int c1 = c0 + (C + 1);
        const int m0 = c1 + (C + 1);
        //const int m1 = m0 + (M + 1);
        const int source = m0 + (M + 1);
        const int dest = source + 1;
        graph g(V);
        for(int i=0; i<H; ++i) {
            add_edge(g, i, w0, 1); // h -> dummy w
        }
        for(int i=0; i<W; ++i) {
            int n;
            cin >> n;
            for(int j=0; j<n; ++j) {
                int h;
                cin >> h;
                h--;
                add_edge(g, h, w0+i+1, 1); // h -> w
            }
            add_edge(g, w0+i+1, w1+i+1, 1); // w -> w
            add_edge(g, w1+i+1, c0, 1); // w -> dummy c
        }
        add_edge(g, w0, w1, Nw); // dummy w -> dummy w
        for(int i=0; i<C; ++i) {
            int n;
            cin >> n;
            for(int j=0; j<n; ++j) {
                int w;
                cin >> w;
                add_edge(g, w1 + w, c0 + i + 1, 1); // w -> c
            }
            add_edge(g, w1, c0 + i + 1, 1); // dummy w -> c
            add_edge(g, c0 + i + 1, c1 + i + 1, 1); // c -> c
            add_edge(g, c1 + i + 1, m0, 1); // c -> dummy m
        }
        add_edge(g, c0, c1, Nc); // dummy c -> dummy c
        for(int i=0; i<M; ++i) {
            int n;
            cin >> n;
            for(int j=0; j<n; ++j) {
                int c;
                cin >> c;
                add_edge(g, c1 + c, m0 + i + 1, 1);
            }
            add_edge(g, c1, m0 + i + 1, 1); // dummy c -> m
            add_edge(g, m0+i+1, dest, 1); // m -> dest
        }
        add_edge(g, m0, dest, Nm);

        for(int i=0; i<H; ++i) {
            add_edge(g, source, i, 1); // source -> hero
        }

        cout << max_flow(g, source, dest) << endl;
    }
}
