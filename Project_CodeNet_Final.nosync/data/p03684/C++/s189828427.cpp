#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator> 
#include <limits>

#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define RALL(A) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair

#define dump(x) cerr << #x << " = " << (x) << endl;

using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define MAX_E 1000000
#define MAX_V 200000

struct edge {int u, v, cost; };
edge  es[MAX_E];
int V, E;

// Kruscal uses union-find tree
int par[MAX_V];
int uf_rank[MAX_V];

void init_union_find(int v) {
    for (int i = 0; i < v; i++) {
        par[i] = i;
        uf_rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (uf_rank[x] < uf_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (uf_rank[x] == uf_rank[y]) {
            uf_rank[x]++;
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

LL kruscal() {
    sort(es, es + E, comp);
    init_union_find(V);
    LL res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int N;
VI X;
VI Y;

struct point_tx {
    int id;
    int x;

    bool operator<( const point_tx& right ) const {
        return x < right.x;
    }
};

struct point_ty {
   int id;
   int y;

    bool operator<( const point_ty& right ) const {
        return y < right.y;
    }
};

int main(int argc, char const* argv[])
{
    cin >> N;
    vector<point_tx> tx_lst;
    vector<point_ty> ty_lst;
    REP(i, N) {
        V += 1;
        int x, y;
        cin >> x >> y;
        point_tx px = point_tx{i, x};
        point_ty py = point_ty{i, y};
        tx_lst.PB(px);
        ty_lst.PB(py);
    }
    sort(ALL(tx_lst));
    sort(ALL(ty_lst));
    int edge_ind = 0;
    REP(i, N - 1) {
        edge e = edge{tx_lst[i].id, tx_lst[i + 1].id, tx_lst[i + 1].x - tx_lst[i].x};
        es[edge_ind++] = e;
        E += 1;
    }
    REP(i, N - 1) {
        edge e = edge{ty_lst[i].id, ty_lst[i + 1].id, ty_lst[i + 1].y - ty_lst[i].y};
        es[edge_ind++] = e;
        E += 1;
    }
    LL ans = kruscal();
    cout << ans << endl;
    return 0;
}
