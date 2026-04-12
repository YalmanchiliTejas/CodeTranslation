#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100000+10;
const int maxm = 200000+10;
const int mod = 1e9+7;
const double eps = 1e-9;
struct Edge{
    int u,v,w;
    Edge(){}
    bool operator < (const Edge &rhs){
        return w<rhs.w;
    }
}edge[maxn<<1];
pii x[maxn],y[maxn];
int fa[maxn];
int Find(int u){
    return u==fa[u]?u:fa[u]=Find(fa[u]);
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin>>n;
    for (int i=0;i<n;i++){
        cin>>x[i].X>>y[i].X;
        x[i].Y=y[i].Y=i;
        fa[i]=i;
    }
    sort(x,x+n);
    sort(y,y+n);
    int tot=0;
    for (int i=1;i<n;i++){
        edge[tot].u=x[i-1].Y; edge[tot].v=x[i].Y; edge[tot++].w=x[i].X-x[i-1].X;
        edge[tot].u=y[i-1].Y; edge[tot].v=y[i].Y; edge[tot++].w=y[i].X-y[i-1].X;
    }
    sort(edge,edge+tot);
    int ans=0;
    for (int i=0;i<tot;i++){
        int u=Find(edge[i].u),v=Find(edge[i].v);
        if (u!=v){
            ans+=edge[i].w;
            fa[u]=v;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
