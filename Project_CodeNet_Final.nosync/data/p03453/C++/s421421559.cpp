#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
const long long mod = 1e9+7;
struct Edge{
    int u,v;
    long long d;
    Edge(){}
    Edge(int u,int v,long long d):u(u),v(v),d(d){}
};
struct Node{
    int u;
    long long value;
    Node(int u,long long value):u(u),value(value){}
    bool operator < (const Node &other)const{
        return value>other.value;
    }
};
std::vector<Edge>g[100005];
std::vector<Edge>allEdge;
long long disS[100005], disT[100005];
long long countS[100005], countT[100005];
int order[100005];

void dijkstra(int s,int n,long long dis[]){ 
    dis[s] = 0;
    std::priority_queue<Node>Q;
    Q.push(Node(s,dis[s]));
    while(Q.size()!=0){
        while(Q.size()!=0 && Q.top().value>dis[Q.top().u]) Q.pop();
        if(Q.size()==0) break;
        Node u = Q.top(); Q.pop();
        for(Edge e: g[u.u]){
            int v = e.v; long long d = e.d;
            if(dis[u.u]+d<dis[v]){
                dis[v] = dis[u.u]+d;
                Q.push(Node(v,dis[v]));
            }
        }
    }
}

void preWork(int s,int n,long long count[],long long dis[]){
    long long inf = 1e16+7;
    for(int i = 1; i <= n; i++) dis[i] = inf, count[i] = 0;
    dijkstra(s,n,dis);
    for(int i = 1; i <= n; i++) order[i] = i;
    std::sort(order+1,order+1+n,[&](int u,int v){ return dis[u]<dis[v]; });
    for(int i = 1; i <= n; i++){
        int u = order[i];
        if(u==s) count[u] = 1;
        //printf("count[%d] = %lld\n",u,count[u]);
        for(Edge e: g[u]){
            int v = e.v; long long d = e.d;
            if(dis[u]+d==dis[v]) count[v] = (count[v]+count[u])%mod;
        }
    }
}

int main(){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i = 0; i < m; i++){
        int u,v; long long d;
        scanf("%d%d%lld",&u,&v,&d);
        allEdge.push_back(Edge(u,v,d));
        g[u].push_back(Edge(u,v,d));
        g[v].push_back(Edge(v,u,d));
    }
    preWork(s,n,countS,disS);
    preWork(t,n,countT,disT);
    long long shortRoad = disS[t];
    //printf("short = %lld\n",shortRoad);
    long long minus = 0;
    for(int i = 1; i <= n; i++){
        if(disS[i]+disT[i]==shortRoad){
            if(disS[i]==disT[i]){
                //printf("i = %d\n",i);
                long long mul = countS[i]*countT[i]%mod;
                minus += mul*mul%mod;
                if(minus>=mod) minus -= mod;
            }
        }
    }
    for(Edge e: allEdge){
        int u = e.u, v = e.v;
        long long d = e.d;
        if(disS[u]+disT[v]+d==shortRoad){
            long long t0 = disS[u], t1 = disS[v];
            if(t0*2!=shortRoad && t1*2!=shortRoad){
                if(2*t0<shortRoad && shortRoad<2*t1){
                    //printf("u = %d, v = %d\n",u,v);
                    long long wayS = countS[u]*countT[v]%mod;
                    long long wayT = countT[v]*countS[u]%mod;
                    minus += wayS*wayT%mod;
                    if(minus>=mod) minus -= mod;
                }
            } 
        }
        if(disT[u]+disS[v]+d==shortRoad){
            int mid = u;
            u = v;
            v = mid;
            long long t0 = disS[u], t1 = disS[v];
            if(t0*2!=shortRoad && t1*2!=shortRoad){
                if(2*t0<shortRoad && shortRoad<2*t1){
                    //printf("u = %d, v = %d\n",u,v);
                    long long wayS = countS[u]*countT[v]%mod;
                    long long wayT = countT[v]*countS[u]%mod;
                    minus += wayS*wayT%mod;
                    if(minus>=mod) minus -= mod;
                }
            } 
        }
    }
    long long answer = countS[t]*countT[s]%mod;
    //printf("all = %lld\n",answer);
    answer -= minus;
    if(answer<0) answer += mod;
    printf("%lld\n",answer);
    return 0;
}
