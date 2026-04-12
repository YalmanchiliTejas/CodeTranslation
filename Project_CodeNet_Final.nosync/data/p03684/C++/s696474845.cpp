#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

typedef ll Weight;
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

class Prim {
public:
    Prim(const Graph &G, int root = 0) :sum(0), mst(G.size()) {
        int V = (int)G.size();
        vector<int> visited(V);
        priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

        PQ.push(Edge(root, root, 0));
        while (PQ.size()) {
            Edge e = PQ.top(); PQ.pop();
            int v = e.to;
            if (visited[v]++) continue;
            if (v != root) {
                mst[e.from].push_back(e);
                mst[v].emplace_back(v, e.from, e.wei);
                sum += e.wei;
            }
            for (const auto &ee : G[v]) {
                if (!visited[ee.to]) {
                    PQ.push(ee);
                }
            }
        }
    }

    Weight getWeight() {
        return sum;
    }

    Graph getMST() {
        return mst;
    }
private:
    Weight sum;
    Graph mst;
};

using P = tuple<int, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    Graph G(N);
    vector<P> S(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        S[i] = mt(x, y, i);
    }
    sort(all(S));
    rep(i,sz(S)-1) {
        int x, y, k, xx, yy, kk;
        tie(x, y, k) = S[i];
        tie(xx, yy, kk) = S[i + 1];
        G.addUEdge(k, kk, xx - x);
    }
    each(p, S) {
        swap(get<0>(p), get<1>(p));
    }
    sort(all(S));
    rep(i, sz(S) - 1) {
        int x, y, k, xx, yy, kk;
        tie(x, y, k) = S[i];
        tie(xx, yy, kk) = S[i + 1];
        G.addUEdge(k, kk, xx - x);
    }

    ll ans = Prim(G).getWeight();
    cout << ans << endl;
}
