#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

typedef int Weight;
struct Edge {
    int from, to;
    Weight wei;
    Edge(int from_, int to_, Weight wei_) :from(from_), to(to_), wei(wei_) {}
};
typedef vector<Edge> Edges;
const Weight INFW = numeric_limits<Weight>::max();
struct Graph : public vector<Edges> {
    Graph() { }
    Graph(int V) : vector<Edges>(V) { }
    /*
    有向辺を追加する
    */
    void addEdge(int from, int to, Weight wei = 1) {
        (*this)[from].push_back(Edge(from, to, wei));
    }
    /*
    無向辺を追加する
    */
    void addUEdge(int u, int v, Weight wei = 1) {
        (*this)[u].push_back(Edge(u, v, wei));
        (*this)[v].push_back(Edge(v, u, wei));
    }
};
bool operator>(const Edge &a, const Edge &b) {
    return a.wei>b.wei;
}

vector<Weight> dijkstra(const Graph &G, int src, int x, int y) {
    typedef pair<Weight, int> pwi;
    priority_queue<pwi, vector<pwi>, greater<pwi>> pq;
    pq.push(mp(0, src));
    int V = (int)G.size();
    vector<Weight> res(V, -1);
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        Weight d = p.first;
        int v = p.second;
        if (res[v] > -1)continue;
        res[v] = d;
        for (const auto &edge : G[v]) {
            int to = edge.to;
            Weight wei = edge.wei;
            if (wei == -1)wei = x;
            if (wei == -2)wei = y;
            pq.push(make_pair(d + wei, to));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int A, B;
    cin >> A >> B;

    const int N = 101 * 2, M = 100 * 2 + 101 * 101;
    auto d = vv(int, A + 1, B + 1, 0);
    FOR(x, 1, A + 1)FOR(y, 1, B + 1)cin >> d[x][y];
    auto f = vv(int, 101, 101, 0);

    Graph G(N);
    rep(a, 101)rep(b, 101) {
        FOR(x, 1, A + 1)FOR(y, 1, B + 1) {
            smax(f[a][b], d[x][y] - x*a - y*b);
        }
        G.addEdge(a, N-1-b, f[a][b]);
    }
    rep(i, 100) {
        G.addEdge(i, i + 1, -1);
        G.addEdge(101 + i, 101 + i + 1, -2);
    }

    FOR(x, 1, A + 1)FOR(y, 1, B + 1) {
        int dist = dijkstra(G, 0, x, y)[N - 1];
        if (dist != d[x][y]) {
            cout << "Impossible" << endl;
            RT 0;
        }
    }

    cout << "Possible" << endl;
    cout << N << ' ' << M << endl;
    rep(i, N)each(e, G[i]) {
        cout << e.from+1 << ' ' << e.to+1 << ' ';
        if (e.wei == -1)cout << 'X';
        else if (e.wei == -2)cout << 'Y';
        else cout << e.wei;
        cout << endl;
    }
    cout << 1 << ' ' << N << endl;
}