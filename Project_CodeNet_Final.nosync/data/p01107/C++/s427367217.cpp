#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

template<typename flow>
struct max_flow {
    struct edge {
        int to;
        flow cap;
        int rev;
    };
    int V;
    vector<vector<edge> > G;
    vector<int> itr, level;
    max_flow(int V) : V(V) {G.assign(V, vector<edge>()); }

    void add_edge(int from, int to, flow cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge) {from, 0, (int)G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto &e : G[v]) {
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    flow dfs(int v, int t, flow f) {
        if(v == t) return f;
        for(int& i = itr[v]; i < (int)G[v].size(); ++i) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                flow d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow run(int s, int t) {
        flow ret = 0, f;
        while(bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};

int H, W;
string field[55];
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
max_flow<int> init() {
    max_flow<int> graph(10001);
    graph.add_edge(1*W+1, 1*W+1+5000, 1);
    graph.add_edge(H*W+1, H*W+1+5000, 1);
    graph.add_edge(H*W+W-1, H*W+W-1+5000, 1);
    graph.add_edge(1*W+W-1, 1*W+W-1+5000, 1);
    for(int h = 1; h <= H; h++) {
        for(int w = 1; w <= W; w++) {
            if(field[h][w] == '#') continue;
             graph.add_edge(h*W + w, h*W + w + 5000, 1);
             for(int k = 0; k <= 3; k++) {
                 int newh = h + dh[k];
                 int neww = w + dw[k];
                 if(newh <= 0 || newh > H || neww <= 0 || neww > W) continue;
                 if(field[newh][neww] == '#') continue;
                 graph.add_edge(h*W+w + 5000, newh*W+neww, 1);
             }
        }
    }
    return graph;
}

int TARGET = 10000;

int main() {
    while(true) {
        cin >> H >> W;
        if(H == 0 && W == 0) break;
        for(int i = 1; i <= H; i++) {
            cin >> field[i];
            field[i] = "&" + field[i];
        }
        bool clear = true;
        max_flow<int> graph = init();
        graph.add_edge(0, 1*W+1, 1);
        graph.add_edge(0, H*W+1, 1);
        graph.add_edge(1*W+W-1 + 5000, TARGET, 1);
        graph.add_edge(H*W+W-1 + 5000, TARGET, 1);
        if(graph.run(0, TARGET) < 2) clear = false;
        graph = init();
        graph.add_edge(0, 1*W+1, 1);
        graph.add_edge(0, 1*W+W-1, 1);
        graph.add_edge(H*W+1 + 5000, TARGET, 1);
        graph.add_edge(H*W+W-1 + 5000, TARGET, 1);
        if(graph.run(0, TARGET) < 2) clear = false;
        graph = init();
        graph.add_edge(0, 1*W+1, 2);
        graph.add_edge(0, H*W+W-1, 2);
        graph.add_edge(1*W+W-1 + 5000, TARGET, 2);
        graph.add_edge(H*W+1 + 5000, TARGET, 2);
        if(graph.run(0, TARGET) < 4) clear = false;
        if(clear) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
