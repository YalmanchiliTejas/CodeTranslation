#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define chmin(a,b) (a)=min((a),(b));
#define chmax(a,b) (a)=max((a),(b));
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) cout<<(#v)<<":";for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;
#define printVS(vs) cout<<(#vs)<<":"<<endl;for(auto(s):(vs)){cout<<(s)<< endl;}
#define printVV(vv) cout<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;}
#define printP(p) cout<<(#p)<<(p).first<<" "<<(p).second<<endl;
#define printVP(vp) cout<<(#vp)<<":"<<endl;for(auto(p):(vp)){cout<<(p).first<<" "<<(p).second<<endl;}

inline void output(){ cout << endl; }
template<typename First, typename... Rest>
inline void output(const First& first, const Rest&... rest) {
    cout << first << " "; output(rest...);
}

using ll = long long;
using Pii = pair<int, int>;
using TUPLE = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const int inf = 1ll << 60;
const int mod = 1e9 + 7;
// using Graph = vector<vector<int>>;

struct edge {
    int from, to, reversed, rev;
    edge(){}
    edge(int _from, int _to, int _reversed, int _rev) : from(_from), to(_to), reversed(_reversed), rev(_rev) {}
    void print() {
        output(from, to, reversed, rev);
    }
};
using Graph = vector<vector<edge>>;

int n, m;
Graph G;
vi indeg;
int mi, ma;
vector<edge> path;
bool visited[100];

// directed
void addEdge(int x, int y) {
    G[x].emplace_back(x, y, 0, (int)G[y].size());
    G[y].emplace_back(y, x, 1, (int)G[x].size() - 1);
}

void reversePath() {
    // cerr << "reversePath:" << endl;
    for (auto& e : path) {
        // e.reversed ^= 1;
        G[e.from][G[e.to][e.rev].rev].reversed ^= 1;
        G[e.to][e.rev].reversed ^= 1;
    }
}

bool dfs(int now, int pre, int cond) {
    // cerr << "dfs:"; output(now, pre);
    // start->...->end (directed path)
    if ((cond ? indeg[now] >= mi + 2 : indeg[now] == ma)) {
        reversePath();
        indeg[path[0].from]++;
        indeg[path.back().to]--;
        return true;
    }

    visited[now] = true;

    for (auto e : G[now]) {
        if (e.to == pre) continue;
        if (visited[e.to]) continue;
        if (e.reversed) continue;

        path.emplace_back(e);
        if (dfs(e.to, now, cond)) return true;
        path.pop_back();
    }

    // visited[now] = false;

    return false;
}

bool update() {
    mi = *min_element(all(indeg));
    ma = *max_element(all(indeg));

    // cerr << "update:"; output(mi, ma);

    if (ma - mi <= 1) return false;

    rep(i, n) {
        if (indeg[i] <= ma - 2) {
            path.clear();
            memset(visited, 0, sizeof(visited));
            if (dfs(i, -1, indeg[i] == mi)) {
                return true;
            }
        }
    }

    return false;
}

void printGraph(const Graph& G) {
    rep(i, G.size()) {
        cout << i << ": ";
        rep(j, G[i].size()) {
            cout << "{" << G[i][j].to << ", " << G[i][j].reversed << ", " << G[i][j].rev << "}, ";
        }
        cout << endl;
    }
}

main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int testcase = 0;
    while (cin >> n >> m, n) {
        // // cerr << "--- testcase = " << ++testcase << " ---" << endl;
        //
        G.clear(); G.resize(n);
        indeg.clear(); indeg.resize(n);
        rep(i, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            addEdge(u, v);
            indeg[v]++;
        }

        // printGraph(G);
        // printV(indeg);

        while (update()) {
            // printV(indeg);
            // output(mi, ma);
            // printGraph(G);
        }

        cout << mi << " " << ma << endl;
    }
}