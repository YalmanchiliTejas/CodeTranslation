#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

struct union_find{
    VI par;

    void init(int n){
        par.resize(n);
        REP(i,n) par[i] = i;
    }

    int find(int x){
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;
        par[x] = y;
    }
};

struct edge{ int u, v, cost; };
VL em[4000], um[4000];
int ma[4000][4000];

bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}

ll kruskal(vector<edge> &es, int n){
    sort(es.begin(), es.end(), comp);
    union_find uf;
    uf.init(n);
    ll res = 0;
    REP(i,es.size()){
        edge e = es[i];
        if (!uf.same(e.u, e.v)){
            uf.merge(e.u, e.v);
            res += e.cost;
            em[e.u].push_back(e.v);
            um[e.u].push_back(e.cost);
            em[e.v].push_back(e.u);
            um[e.v].push_back(e.cost);
        }
    }
    return res;
}

void dfs(int now, int past, ll x, int s){
    ma[s][now] = x;
    REP(i,em[now].size()){
        if (em[now][i] == past) continue;
        dfs(em[now][i], now, max(x, um[now][i]), s);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<edge> es;
    while(m--){
        edge eg;
        scanf("%d %d %d", &eg.u, &eg.v, &eg.cost);
        eg.u--;
        eg.v--;
        es.push_back(eg);
    }

    ll sum = kruskal(es, n);

    REP(i,n) dfs(i, -1, 0, i);

    int q;
    cin >> q;
    while (q--){
        int s, t;
        scanf("%d %d", &s, &t);
        s--;
        t--;
        printf("%lld\n", sum - ma[s][t]);
    }

    return 0;
}
