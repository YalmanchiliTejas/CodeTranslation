#include<bits/stdc++.h>
using namespace std;

int N;
struct Point {
    int x, y, id;
};
vector<Point> P;

bool cmpx(Point a, Point b) {
    return a.x < b.x;
}
bool cmpy(Point a, Point b) {
    return a.y < b.y;
}

struct Edge {
    int u, v, w;
};
vector<Edge> edge;

bool cmpw(Edge a, Edge b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> par, rnk;
    void init() {
        for(int i = 0; i < N; i++) {
            par.push_back(i);
            rnk.push_back(0);
        }
    }
    int f(int u) {
        if(par[u] == u) return u;
        else return par[u] = f(par[u]);
    }
    void mrg(int u, int v) {
        u = f(u);
        v = f(v);
        if(u == v) return;
        if(rnk[u] < rnk[v]) swap(u, v);
        par[v] = u;
        if(rnk[u] == rnk[v]) rnk[u]++;
    }
} dsu;

int main() {
    scanf("%d", &N);
    P.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &P[i].x, &P[i].y);
        P[i].id = i;
    }
    sort(P.begin(), P.end(), cmpx);
    for(int i = 0; i < N - 1; i++) {
        edge.push_back( { P[i].id, P[i + 1].id, P[i + 1].x - P[i].x } );
    }
    sort(P.begin(), P.end(), cmpy);
    for(int i = 0; i < N - 1; i++) {
        edge.push_back( { P[i].id, P[i + 1].id, P[i + 1].y - P[i].y } );
    }
    sort(edge.begin(), edge.end(), cmpw);

    dsu.init();

    long long ans = 0;

    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if(dsu.f(u) == dsu.f(v)) continue;
        ans += w;
        dsu.mrg(u, v);
    }

    printf("%lld", ans);
}
