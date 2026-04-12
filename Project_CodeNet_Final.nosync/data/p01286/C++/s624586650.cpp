#include<bits/stdc++.h>
using namespace std;
using Weight=long long;

struct Edge{
    int to;
    Weight cap,rev;
    Weight cost;
};

using Edges=vector<Edge>;
using Graph=vector<Edges>;

class Flow{
    const Weight INF=1e9+7;
    const bool isNegative=false;
    int N;
    Graph g;
    vector<int> level;
    vector<int> iter;
    void bfs(int s);
    Weight dfs(int v,int t,Weight f);
    public:
    Flow(int N):N(N),g(N){};
    void addEdge(int from,int to,Weight cap);
    void addEdge(int from,int to,Weight cap,Weight cost);
    Weight maxFlow(int s,int t);
    Weight minCostFlow(int s,int t,Weight f);
};


void Flow::addEdge(int from,int to,Weight cap){
    g[from].push_back({to,cap,int(g[to].size()),0});
    g[to].push_back({from,Weight(0),int(g[from].size())-1,0});
}

void Flow::addEdge(int from,int to,Weight cap,Weight cost){
    g[from].push_back({to,cap,int(g[to].size()),cost});
    g[to].push_back({from,Weight(0),int(g[from].size())-1,-cost});
}
Weight Flow::maxFlow(int s,int t){
    Weight flow=0;
    while(true){
        bfs(s);
        if(level[t]<0) return flow;
        iter.assign(N,0);
        Weight f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}
void Flow::bfs(int s){
    level.assign(N,-1);
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front(); que.pop();
        for(int i=0;i<g[v].size();i++){
            Edge &e=g[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

Weight Flow::dfs(int v,int t,Weight f){
    if(v==t) return f;
    for(int& i=iter[v];i<g[v].size();i++){
        Edge& e=g[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            Weight d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

Weight Flow::minCostFlow(int s,int t,Weight f){
    using P=pair<Weight,int>;
    Weight res=0;
    vector<Weight> h(N,0);
    vector<int> used(N),preve(N),prevv(N);
    vector<Weight> dist(N);
    while(f>0){    
        fill(dist.begin(),dist.end(),INF);
        dist[s]=0;
        if(!isNegative){
            //Dijkstra
            fill(used.begin(),used.end(),0);
            priority_queue<P,vector<P>,greater<P>> que;
            que.push(make_pair(Weight(0),s));
            while(!que.empty()){
                P p=que.top(); que.pop();
                int v=p.second;
                if(used[v]) continue;
                used[v]=true;
                for(int i=0;i<g[v].size();i++){
                    Edge &e=g[v][i];
                    if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        que.push(make_pair(dist[e.to],e.to));
                    }
                }
            }
        }else{
            //Bermanford
            bool update=true;
            while(update){
                update=false;
                for(int v=0;v<N;v++){
                    if(dist[v]==INF) continue;
                    for(int i=0;i<g[v].size();i++){
                        Edge &e=g[v][i];
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to]=v;
                            preve[e.to]=i;
                            update=true;
                        }
                    }
                }
            }
        }

        if(dist[t]==INF){
            return -1;
        }
        if(!isNegative){
            for(int v=0;v<N;v++) h[v]+=dist[v];
        }
        Weight d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,g[prevv[v]][preve[v]].cap);
        }
        f-=d;
        if(!isNegative){
            res+=d*h[t];
        }else{
            res+=d*dist[t];
        }
        for(int v=t;v!=s;v=prevv[v]){
            Edge& e=g[prevv[v]][preve[v]];
            e.cap-=d;
            g[v][e.rev].cap+=d;
        }
    }
    return res;
}
enum{HERO,WAR,CLE,MAGE,META};
enum{OUT,IN};
enum{S,T,WW,WC,WM};
const int SIZE=600;
int solve(int h,int w,int c,int m,int nw,int nc,int nm){
    map<tuple<int,int,int>,int> dic;
    int sz=0;
    auto getV=[&](int pro,int type,int v){
        auto x=make_tuple(pro,type,v);
        if(dic.count(x)) return dic[x];
        else return dic[x]=sz++;
    };
    Flow flow(SIZE);
    for(int i=0;i<h;i++){
        flow.addEdge(getV(META,OUT,S),getV(HERO,IN,i),1);
        flow.addEdge(getV(HERO,IN,i),getV(HERO,OUT,i),1);
        flow.addEdge(getV(HERO,OUT,i),getV(META,IN,WW),1);
    }
    for(int i=0;i<w;i++){
        flow.addEdge(getV(WAR,IN,i),getV(WAR,OUT,i),1);
        flow.addEdge(getV(WAR,OUT,i),getV(META,IN,WC),1);
    }
    
    for(int i=0;i<c;i++){
        flow.addEdge(getV(META,OUT,WW),getV(CLE,IN,i),1);
        flow.addEdge(getV(CLE,IN,i),getV(CLE,OUT,i),1);
        flow.addEdge(getV(CLE,OUT,i),getV(META,IN,WM),1);
    }
    for(int i=0;i<m;i++){
        flow.addEdge(getV(META,OUT,WC),getV(MAGE,IN,i),1);
        flow.addEdge(getV(MAGE,IN,i),getV(MAGE,OUT,i),1);
        flow.addEdge(getV(MAGE,OUT,i),getV(META,IN,T),1);
    }
    flow.addEdge(getV(META,IN,WW),getV(META,OUT,WW),nw);
    flow.addEdge(getV(META,IN,WC),getV(META,OUT,WC),nc);
    flow.addEdge(getV(META,IN,WM),getV(META,OUT,WM),nm);
    flow.addEdge(getV(META,OUT,WM),getV(META,IN,T),nm);
    
    
    for(int i=0;i<w;i++){
        int ni;
        cin>>ni;
        while(ni--){
            int hi;
            cin>>hi;
            hi--;
            flow.addEdge(getV(HERO,OUT,hi),getV(WAR,IN,i),1);
        }
    }
    for(int i=0;i<c;i++){
        int ni;
        cin>>ni;
        while(ni--){
            int wi;
            cin>>wi;
            wi--;
            flow.addEdge(getV(WAR,OUT,wi),getV(CLE,IN,i),1);
        }
    }
    for(int i=0;i<m;i++){
        int ni;
        cin>>ni;
        while(ni--){
            int ci;
            cin>>ci;
            ci--;
            flow.addEdge(getV(CLE,OUT,ci),getV(MAGE,IN,i),1);
        }
    }
    return flow.maxFlow(getV(META,OUT,S),getV(META,IN,T));
}
int main(){
    int h,w,c,m,nw,nc,nm;
    while(cin>>h>>w>>c>>m>>nw>>nc>>nm,h!=-1){
        cout<<solve(h,w,c,m,nw,nc,nm)<<endl;
    }
    return 0;
}
