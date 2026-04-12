#include<bits/stdc++.h>

using namespace std;

struct I{I(){ios::sync_with_stdio(false);cin.tie(0);}}init;

struct edge{
    int flow,to,rev;
};
typedef vector<edge> E;
typedef vector<E> Graph;

void addedge(Graph &g,int s,int t,int f){
    int n=g[s].size();
    int m=g[t].size();
    g[s].push_back(edge{f,t,m});
    g[t].push_back(edge{0,s,n});
}

vector<int> bfs(Graph &g,int s){
    int n=g.size();
    queue<int> que;
    vector<int> dist(n,-1);
    dist[s]=0;
    que.push(s);
    for(;que.size();que.pop()){
        auto v=que.front();
        for(auto &e:g[v])
            if(e.flow>0&&dist[e.to]==-1){
                dist[e.to]=dist[v]+1;
                que.push(e.to);
            }
    }
    return dist;
}

int maxflow(Graph &g,int s,int t){
    int res=0;
    int n=g.size();
    while(true){
        auto dist=bfs(g,s);
        if(dist[t]<0)break;
        vector<unsigned> iter(n,0);
        std::function<int(int,int)> dfs=[&](int v,int f){
            if(v==s)return f;
            for(auto &i=iter[v];i<g[v].size();i++){
                edge &e=g[v][i];
                edge &re=g[e.to][e.rev];
                if(re.flow>0&&dist[v]>dist[e.to]){
                    int d=dfs(e.to,min(f,re.flow));
                    if(d>0){e.flow+=d;re.flow-=d;return d;}
                }
            }
            return 0;
        };
        int f;
        while((f=dfs(t,114514))>0)res+=f;
    }
    return res;
}


int main(){
    for(int H,W,C,M,NW,NC,NM;cin>>H>>W>>C>>M>>NW>>NC>>NM,H>=0;){
        int sz=0;
        using P=pair<int,int>;
        vector<P> h,w,c,m;
        for(int i=0;i<H;i++)h.push_back(P(sz++,sz++));
        for(int i=0;i<W;i++)w.push_back(P(sz++,sz++));
        for(int i=0;i<C;i++)c.push_back(P(sz++,sz++));
        for(int i=0;i<M;i++)m.push_back(P(sz++,sz++));

        P  nw(sz++,sz++);
        P  nc(sz++,sz++);
        P  nm(sz++,sz++);
        int S=sz++;
        int T=sz++;
        
        Graph g(sz);
        
        for(int i=0;i<H;i++){
            addedge(g,S,h[i].first,1);
            addedge(g,h[i].first,h[i].second,1);
            addedge(g,h[i].second,nw.first,1);            
        }
        addedge(g,nw.first,nw.second,NW);
        for(int i=0;i<W;i++){
            addedge(g,w[i].first,w[i].second,1);
            addedge(g,w[i].second,nc.first,1);
            int n;cin>>n;
            while(n--){
                int j;cin>>j;j--;
                addedge(g,h[j].second,w[i].first,1);
            }
        }
        addedge(g,nc.first,nc.second,NC);
        for(int i=0;i<C;i++){
            addedge(g,nw.second,c[i].first,1);
            addedge(g,c[i].first,c[i].second,1);
            addedge(g,c[i].second,nm.first,1);
            int n;cin>>n;
            while(n--){
                int j;cin>>j;j--;
                addedge(g,w[j].second,c[i].first,1);
            }
        }
        addedge(g,nm.first,nm.second,NM);
        for(int i=0;i<M;i++){
            addedge(g,nc.second,m[i].first,1);
            addedge(g,m[i].first,m[i].second,1);
            addedge(g,m[i].second,T,1);
            int n;cin>>n;
            while(n--){
                int j;cin>>j;j--;
                addedge(g,c[j].second,m[i].first,1);
            }
        }
        addedge(g,nm.second,T,NM);
        cout<<maxflow(g,S,T)<<endl;
    }

    return 0;
}