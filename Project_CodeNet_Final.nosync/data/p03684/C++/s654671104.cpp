#include <bits/stdc++.h>
using  namespace  std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define mst(ss,b) memset(ss,b,sizeof(ss));
#define dbg(x) cout << #x << "= " << x << endl;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = (1LL<<62)-1;
const ll mod = 1e9+7;
const int N = 1e5+5;

vector<pii >tx, ty;
int n, m, x[N], y[N];
int p[N];    //并查集的使用

const int maxm = 5e5+5;

struct edge{
    int u,v;
    ll cost;
    bool operator < (const edge& rhs)const {
        return cost < rhs.cost;
    }
}e[maxm];

int Find(int x){//查找x的父亲节点，递归调用
    return  p[x]==x?x:p[x]=Find(p[x]);
}

ll kruskal(int n,int m){  //返回最小生成树的权值
    ll ans=0;
    sort(e,e+m);
    for(int i=0 ; i<m ; i++){
        int u=e[i].u;
        int v=e[i].v;
        u=Find(u);
        v=Find(v);
        if(u!=v){   //如果不在一个集合中，合并
            ans+=e[i].cost;
            p[v]=u;
        }
    }
    return ans;
}

void addedge(int u, int v){
    e[m].u = u, e[m].v = v, e[m++].cost = min(abs(x[u]-x[v]), abs(y[u]-y[v]));
}

int  main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)p[i] = i;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &x[i], &y[i]);
        tx.pb({x[i], i});
        ty.pb({y[i], i});
    }
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    addedge(tx[0].ss, tx[1].ss);
    addedge(ty[0].ss, ty[1].ss);
    addedge(tx[n-1].ss, tx[n-2].ss);
    addedge(ty[n-1].ss, ty[n-2].ss);
    for(int i=1; i<n-1; i++){
        addedge(tx[i-1].ss, tx[i].ss);
        addedge(tx[i].ss, tx[i+1].ss);
        addedge(ty[i-1].ss, ty[i].ss);
        addedge(ty[i].ss, ty[i+1].ss);
    }
    printf("%lld\n", kruskal(n, m));
    return 0;
}


//    lower_bound()
//    __builtin_popcount()
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    const double eps=1e-12;
//    #pragma comment(linker,"/STACK:102400000,102400000")

