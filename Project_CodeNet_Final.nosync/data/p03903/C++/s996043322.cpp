#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define mk make_pair
#define pb push_back

int N, M, Q;
struct edge
{
    ll cost;
    int from;
    int to;
};
edge E[400400];

struct branch
{
    int to;
    ll cost;
};

vector<branch> G[4040];

bool cmpc(const edge a, const edge b)
{
    return a.cost < b.cost;
}

int ufpar[4040], ufsize[4040];

void init()
{
    for(int i = 0; i < N; i++){
        ufpar[i] = i;
        ufsize[i] = 1;
    }
    return;
}

int root(int x)
{
    if(ufpar[x] == x)return x;
    return ufpar[x] = root(ufpar[x]);
}

bool same(int x, int y)
{
    return root(x) == root(y);
}

void unite(int x, int y)
{
    x = root(x);
    y = root(y);
    if(x == y)return;
    if(ufsize[x] > ufsize[y])swap(x, y);
    ufsize[y] += ufsize[x];
    ufpar[x] = y;
    return;
}

ll dis[4040], mxe[4040][30];
int dep[4040], par[4040], dpar[4040][30];

void dfs(int v, int p, ll di, int de)
{
    dis[v] = di;
    dep[v] = de;
    par[v] = p;
    for(int i = 0; i < (int)G[v].size(); i++){
        branch e = G[v][i];
        if(p == e.to)continue;
        dfs(e.to, v, di + e.cost, de + 1);
    }
    return;
}

int LCA(int x, int y)
{
    if(dep[x] > dep[y])swap(x, y);
    int dif = dep[y] - dep[x];
    for(int i = 20; i >= 0; i--){
        if((dif >> i) & 1){
            y = dpar[y][i];///深いほうを深い分だけ浅くしていく
        }
    }
    if(x == y)return x;
    for(int i = 20; i >= 0; i--){
        if(dpar[x][i] != dpar[y][i]){
            x = dpar[x][i];
            y = dpar[y][i];
        }
    }
    return dpar[x][0];
}

ll pathmax(int l, int x)
{
    int dif = dep[x] - dep[l];
    ll ret = 0;
    for(int i = 20; i >= 0; i--){
        if((dif >> i) & 1){
            ret = max(ret, mxe[x][i]);
            x = dpar[x][i];
        }
    }
    return ret;
}

signed main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        E[i] = {c, a, b};
    }
    sort(E, E + M, cmpc);
    init();
    ll csum = 0ll;
    for(int i = 0; i < M; i++){
        edge e = E[i];
        if(!same(e.from, e.to)){///UF木
            unite(e.from, e.to);
            G[e.from].pb({e.to, e.cost});
            csum += e.cost;
            G[e.to].pb({e.from, e.cost});
        }
    }
    dfs(0, -1, 0ll, 0);///各頂点の親と深さと根からの距離を保存
    for(int i = 0; i < N; i++){///ダブリング
        dpar[i][0] = par[i];
        if(par[i] < 0) mxe[i][0] = 0ll;
        else mxe[i][0] = dis[i] - dis[par[i]];
    }
    for(int k = 0; k < 20; k++){
        for(int i = 0; i < N; i++){
            if(dpar[i][k] < 0){
                dpar[i][k + 1] = -1;
                mxe[i][k + 1] = 0ll;
            }
            else {
                dpar[i][k + 1] = dpar[dpar[i][k]][k];
                mxe[i][k + 1] = max(mxe[i][k], mxe[dpar[i][k]][k]);
            }
        }
    }
    ///query & LCA
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int L = LCA(a, b);
        //ll res = dis[a] - dis[L] + dis[b] - dis[L];
        //printf("LCA:%d dis[a]:%lld dis[b]:%lld dis[LCA]:%lld\n", L, dis[a], dis[b], dis[L]);
        ll res = max(pathmax(L, a), pathmax(L, b));
        printf("%lld\n", csum - res);
    }
    /*
    for(int i = 0; i < N; i++){
        printf("dis[%d]:%lld dep[%d]:%d\n", i, dis[i], i, dep[i]);
    }
    for(int i = 0; i < N; i++){
        printf("dpar[%d][0]:%d\n", i, dpar[i][0]);
    }
    */

    return 0;
}
