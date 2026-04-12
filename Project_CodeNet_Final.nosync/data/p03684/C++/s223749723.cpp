#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF   = 1e9;
const ll  INFLL = 1e18;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

struct Node { int id, x, y; };
bool cmp1(const Node &lhs, const Node &rhs) { return lhs.x < rhs.x; }
bool cmp2(const Node &lhs, const Node &rhs) { return lhs.y < rhs.y; }

int N;

struct Edge {
    int u, v, cost;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), cost(_c) {}
    bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
};

const int MAX_N = 100000;
class UnionFind {
private:
    int union_size[MAX_N];
    int rank[MAX_N];

public:
    int par[MAX_N];
    
    void init(int n)
    {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
            union_size[i] = 1;
        }
    }
    
    int find(int x)
    {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;

        union_size[x] += union_size[y];
        union_size[y] = union_size[x];

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
    
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    
    int getUnionSize(int x)
    {
        return union_size[find(x)];
    }
};

vector<Edge> G;
ll kruskal()
{
    UnionFind UF;
    sort(G.begin(), G.end());
    UF.init(N);
    ll res=0;
    for (Edge e : G) {
        if (!UF.same(e.u, e.v)) {
            UF.merge(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> N;
    vector<Node> VS(N);
    rep(i, N) {
        int X, Y;
        cin >> X >> Y;
        VS[i] = {i, X, Y};
    }

    sort(VS.begin(), VS.end(), cmp1);
    rep(i, N-1) {
        int cost = min(abs(VS[i].x - VS[i+1].x), abs(VS[i].y - VS[i+1].y)); 
        G.push_back(Edge(VS[i].id, VS[i+1].id, cost));
    }

    sort(VS.begin(), VS.end(), cmp2);
    rep(i, N-1) {
        int cost = min(abs(VS[i].x - VS[i+1].x), abs(VS[i].y - VS[i+1].y)); 
        G.push_back(Edge(VS[i].id, VS[i+1].id, cost));
    }

    cout << kruskal() << endl;
}