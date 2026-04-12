#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e9;
const long double PI = acos(-1.0L);
struct max_flow {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
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

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};

//const ll mod = 1000000007;
int H, W, C, M, NW, NC, NM;

void solve() {
    int s = 800;
    int t = 808;
    int NotW = 802;
    int NotC = 804;
    int NotM = 806;
    max_flow g(t + 1);
    for(int h = 0; h < H; h++) {
        g.add_edge(s, h, 1);
        g.add_edge(h, h + 50, 1);
        g.add_edge(h + 50, NotW, H);
    }
    g.add_edge(NotW, NotW + 1, NW);
    g.add_edge(NotC, NotC + 1, NC);
    g.add_edge(NotM, NotM + 1, NM);
    for(int w = 0; w < W; w++) {
        g.add_edge(100 + w, 150 + w, 1);
        g.add_edge(150 + w, NotC, H);
    }
    for(int c = 0; c < C; c++) {
        g.add_edge(NotW + 1, 200 + c, H);
        g.add_edge(200+c, 250+c, 1);
        g.add_edge(250+c, NotM, 1);
    }
    for(int m = 0; m < M; m++) {
        g.add_edge(NotC+1, 300+m, 1);
        g.add_edge(300+m, 350+m, 1);
        g.add_edge(350+m, t, 1);
    }
    g.add_edge(NotM+1, t, H);
    for(int w = 0; w < W; w++) {
        int n;
        cin >> n;
        while(n--) {
            int a;
            cin >> a;
            a--;
            g.add_edge(50 + a, 100 + w, 1);
        }
    }
    for(int c = 0; c < C; c++) {
        int n;
        cin >> n;
        while(n--) {
            int a;
            cin >> a;
            a--;
            g.add_edge(150 + a, 200 + c, 1);
        }
    }
    for(int m = 0; m < M; m++) {
        int n;
        cin >> n;
        while(n--) {
            int a;
            cin >> a;
            a--;
            g.add_edge(250 + a, 300 + m, 1);
        }
    }
    int ans = g.run(s, t);
    cout << ans << endl;
}

int main() {
    while(cin >> H >> W >> C >> M >> NW >> NC >> NM) {
        if(H < 0) break;
        solve();
    }
    return 0;
}
