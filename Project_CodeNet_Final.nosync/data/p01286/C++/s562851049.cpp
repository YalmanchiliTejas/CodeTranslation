#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

template<typename T>
struct Dinic {
    // O(EV^2)
    struct edge {
        int to, rev;
        T cap;
        edge(int to, T cap, int rev) :
                to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> g;
    vector<int> level, iter;
    const T INF;

    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}

    void add_edge(int s, int t, T cap) {
        g[s].emplace_back(t, cap, (int)g[t].size());
        g[t].emplace_back(s,   0, (int)g[s].size() - 1);
    }

    bool bfs(int s, int t) {
        level.assign(g.size(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : g[v]) {
                if (e.cap > 0 and level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int v, const int t, T flow) {
        if (v == t) return flow;
        for (int &i = iter[v]; i < g[v].size(); ++i) {
            edge &e = g[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            iter.assign(g.size(), 0);
            T f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    for (;;) {
        int H, W, C, M, Nw, Nc, Nm;
        cin >> H >> W >> C >> M >> Nw >> Nc >> Nm;
        if (H == -1) break;

        int S = H+2*W+2*C+M, T = S+1;
        Dinic<int> flow(T+6);
        REP(i, W) {
            int n; cin >> n;
            REP(_, n) {
                int v; cin >> v; --v;
                flow.add_edge(v, i+H, 1);
            }
        }
        REP(i, C) {
            int n; cin >> n;
            REP(_, n) {
                int v; cin >> v; --v;
                flow.add_edge(v+H+W, i+H+2*W, 1);
            }
        }
        REP(i, M) {
            int n; cin >> n;
            REP(_, n) {
                int v; cin >> v; --v;
                flow.add_edge(v+H+2*W+C, i+H+2*W+2*C, 1);
            }
        }


        REP(i, H) {
            flow.add_edge(S, i, 1);
        }
        REP(i, W) {
            flow.add_edge(i+H, i+H+W, 1);
        }
        REP(i, C) {
            flow.add_edge(i+H+2*W, i+H+2*W+C, 1);
        }
        REP(i, M) {
            flow.add_edge(i+H+2*W+2*C, T, 1);
        }

        REP(i, H) {
            flow.add_edge(i, T+1, 1);
        }
        REP(i, W) {
            flow.add_edge(i+H+W, T+3, 1);
        }
        REP(i, C) {
            flow.add_edge(i+H+2*W+C, T+5, 1);
            flow.add_edge(T+2, i+H+2*W, 1);
        }
        REP(i, M) {
            flow.add_edge(T+4, i+H+2*W+2*C, 1);
        }
        flow.add_edge(T+1, T+2, Nw);
        flow.add_edge(T+3, T+4, Nc);
        flow.add_edge(T+5, T, Nm);

        int ans = flow.max_flow(S, T);
        cout << ans << endl;
    }

    return 0;
}

