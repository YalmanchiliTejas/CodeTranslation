#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
typedef pair<int,pii> pipii;
typedef pair<ll,pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1<<30;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod

int n, m;
int cost[4005][4005];

class UnionFind {
    public:
        vector<int> parent, rank;
        vector<vector<int>> group;
        UnionFind(int size) {
            group.resize(size);
            for (int i = 0; i < size; i++) {
                parent.push_back(i);
                rank.push_back(0);
                group[i].push_back(i);
            }
        }

        int findset(int x) {
            return x == parent[x] ? x : parent[x] = findset(parent[x]);
        }

        void unite(int x, int y, int c) {
            x = findset(x); y = findset(y);
            if (x == y) return;
            if (rank[x] > rank[y]) swap(x, y);
            parent[x] = y;
            for (auto nodey : group[y]) {
                for (auto nodex : group[x]) {
                    cost[nodey][nodex] = c;
                    cost[nodex][nodey] = c;
                }
            }
            for (auto ch : group[x]) {
                group[y].push_back(ch);
            }
            if (rank[x] == rank[y]) rank[y] += 1;
        }

        bool same(int x, int y) {
            return findset(x) == findset(y);
        }
};

struct edge {ll cost, u, v;};
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

vector<edge> es;

ll kruskal(int v, int e, vector<edge> es) {//vは頂点数,eは辺数
    sort(all(es), comp);   //esは[辺の重み,辺の端点1,辺の端点2]
    UnionFind node(v);
    ll ret = 0;
    for (int i = 0; i < e; i++) {
        edge e = es[i];
        if (!node.same(e.u, e.v)) {
            ret += e.cost;
            node.unite(e.u, e.v, e.cost);
        }
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        es.push_back(edge{c, a, b});
    }
    int total = kruskal(n, m, es);
    int q;
    cin >> q;
    rep(i, q) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << total - cost[s][t] << endl;
    }
}
