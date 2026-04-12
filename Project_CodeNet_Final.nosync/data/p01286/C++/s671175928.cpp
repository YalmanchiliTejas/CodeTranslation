#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

struct Edge{
    int dst, cap, rev;
};
typedef vector<Edge> Node;
typedef vector<Node> Graph;

const int INF = 1000000000;

struct Dinic{
    Graph G;
    vector<int> level;
    vector<int> iter;
    
    Dinic(int N) : G(N), level(N), iter(N) {}

    void bfs(int s){
        level.assign(G.size(), -1);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(const auto& e : G[v]){
                if(e.cap > 0 && level[e.dst] < 0){
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        for(int& i = iter[v]; i < G[v].size(); i++){
            Edge& e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.dst]){
                int d = dfs(e.dst, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.dst][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    void add_edge(int src, int dst, int cap){
        assert(src < G.size());
        assert(dst < G.size());
        G[src].push_back({dst, cap, (int)G[dst].size()});
        G[dst].push_back({src, 0, (int)G[src].size() - 1});
    }

    int max_flow(int src, int dst){
        int flow = 0;
        while(true){
            bfs(src);
            if(level[dst] < 0) break;
            iter.assign(G.size(), 0);
            while(true){
                int f = dfs(src, dst, INF);
                if(f <= 0) break;
                flow += f;
            }
        }
        return flow;
    }
};

int H, W, C, M, NW, NC, NM;
int get(int type, int idx, int out) {
    assert(type >= 0 && type < 4);
    assert(idx >= 0);
    assert(out == 0 || out == 1);
    if(type == 0) {
        // H
        assert(idx < H);
        return idx;
    } else if(type == 1) {
        // W
        assert(idx <= W);
        return H + out * (W + 1) + idx;
    } else if(type == 2) {
        // C
        assert(idx <= C);
        return H + 2 * (W + 1) + out * (C + 1) + idx;
    } else if(type == 3) {
        // M
        assert(idx <= M);
        return H + 2 * (W + 1) + 2 * (C + 1) + out * (M + 1) + idx;
    }
}


int main(){
    while(cin >> H >> W >> C >> M >> NW >> NC >> NM && H >= 0) {
        const int SRC = 2 * (M + 1 + C + 1 + W + 1) + H;
        const int DST = SRC + 1;
        Dinic solver(DST + 1);
        // src -> M
        REP(i, M) solver.add_edge(SRC, get(3, i, 0), 1);

        // use once
        REP(i, M + 1) solver.add_edge(get(3, i, 0), get(3, i, 1), (i < M ? 1 : NM));
        REP(i, C + 1) solver.add_edge(get(2, i, 0), get(2, i, 1), (i < C ? 1 : NC));
        REP(i, W + 1) solver.add_edge(get(1, i, 0), get(1, i, 1), (i < W ? 1 : NW));

        // not use
        solver.add_edge(SRC, get(3, M, 0), NM); // M-in
        REP(j, C) solver.add_edge(get(3, M, 1), get(2, j, 0), 1); // M-out
        REP(i, M) solver.add_edge(get(3, i, 1), get(2, C, 0), 1); // C-in
        REP(j, W) solver.add_edge(get(2, C, 1), get(1, j, 0), 1); // C-out
        REP(i, C) solver.add_edge(get(2, i, 1), get(1, W, 0), 1); // W-in
        REP(j, H) solver.add_edge(get(1, W, 1), get(0, j, 0), 1); // W-out

        // H -> dst
        REP(i, H) solver.add_edge(get(0, i, 1), DST, 1);

        REP(i, W) {
            int K;
            cin >> K;
            while(K--) {
                int id;
                cin >> id;
                id--;
                solver.add_edge(get(1, i, 1), get(0, id, 0), 1);
            }
        }
        REP(i, C) {
            int K;
            cin >> K;
            while(K--) {
                int id;
                cin >> id;
                id--;
                solver.add_edge(get(2, i, 1), get(1, id, 0), 1);
            }
        }
        REP(i, M) {
            int K;
            cin >> K;
            while(K--) {
                int id;
                cin >> id;
                id--;
                solver.add_edge(get(3, i, 1), get(2, id, 0), 1);
            }
        }

        cout << solver.max_flow(SRC, DST) << endl;
    }
    return 0;
}