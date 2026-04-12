#include<iostream>
#include<cstdio>
#include<queue>
typedef long long ll;
const int N=1e5+5;
const ll INF=1e17+7;
const ll mod=1e9+7;
int n,m,cnt,head[N],s,t;ll d[N],num[N],rd[N],rn[N];
ll ans=0,len;
void init() {
    for(int i=1;i<=n;i++) head[i]=-1;cnt=0;
}
struct Edge {
    int to,nxt;ll w;
}edge[N<<2];
void addEdge(int from,int to,ll w) {
    edge[cnt].to=to;edge[cnt].nxt=head[from];edge[cnt].w=w;head[from]=cnt++;
}
struct Node {
    int p;ll w;
    Node(int p=0,ll w=0):p(p),w(w){};
    bool operator < (const Node &b) const {
        return w>b.w;
    }
};
std::priority_queue<Node> q;
void dijkstra(int s,ll *d,ll *num) {
    for(int i=1;i<=n;i++) d[i]=INF,num[i]=0;
    d[s]=0,num[s]=1;
    while(!q.empty()) q.pop();
    q.push(Node(s,0));
    while(!q.empty()) {
        Node c=q.top();q.pop();
        if(d[c.p]<c.w) continue;
        for(int i=head[c.p];~i;i=edge[i].nxt) {
            int v=edge[i].to;
            if(d[v]>d[c.p]+edge[i].w) d[v]=d[c.p]+edge[i].w,num[v]=num[c.p],q.push(Node(v,d[v]));
            else if(d[v]==d[c.p]+edge[i].w) num[v]+=num[c.p],num[v]%=mod;
        }
    }
}
void solve() {
    dijkstra(s,d,num);dijkstra(t,rd,rn);len=d[t];
    for(int i=1;i<=n;i++) {
        if(d[i]<<1==len&&d[i]==rd[i]) ans+=num[i]*rn[i]%mod*(num[t]-num[i]*rn[i]%mod+mod)%mod,ans%=mod;
        if(d[i]<<1<len) {
            for(int j=head[i];~j;j=edge[j].nxt) {
                int v=edge[j].to;
                if(rd[v]+d[i]+edge[j].w!=len) continue;
                if(d[v]<<1>len&&d[i]<<1<len) ans+=num[i]*rn[v]%mod*(num[t]-num[i]*rn[v]%mod+mod)%mod,ans%=mod;
            }
        }
    }
    printf("%lld\n",ans);
}
int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    init();int u,v,w;
    while(m--) {
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    solve();
    return 0;
}
