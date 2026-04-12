#include <bits/stdc++.h>
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef vector<V> VV;
const int INF = 1e9;

const int MAX_N = 100010;

int par[MAX_N];
int myrank[MAX_N];

void init(int n)
{
    for (int i=0; i<n; i++) {
        par[i] = i;
        myrank[i] = 0;
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

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (myrank[x] < myrank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (myrank[x] == myrank[y]) myrank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int N;
int X[100010], Y[100010];
pair<int, int> x[100010];
pair<int, int> y[100010];

struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}
edge es[400010];

signed main()
{
    cin >> N;
    REP(i,N) {
        cin >> X[i];
        x[i].first = X[i];
        x[i].second = i;
        cin >> Y[i];
        y[i].first = Y[i];
        y[i].second = i;
    }

    sort(x, x + N);
    sort(y, y + N);

    REP(i,N-1) {
        edge e;
        e.u = x[i].second;
        e.v = x[i+1].second;
        e.cost = x[i+1].first - x[i].first;
        es[i] = e;
    }
    REP(i,N-1) {
        edge e;
        e.u = y[i].second;
        e.v = y[i+1].second;
        e.cost = y[i+1].first - y[i].first;
        es[N-1+i] = e;
    }

    sort(es, es + 2 * N - 2, comp);
    init(N);
    int res = 0;
    for (int i=0; i<2*N-2; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }

    cout << res << endl;
}
